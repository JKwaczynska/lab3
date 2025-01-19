#include <iostream>
#include <string>

// Klasa bazowa Robot
class Robot {
public:
    virtual void operacja() = 0;  // Wirtualna metoda operacji
    virtual ~Robot() = default;    // Wirtualny destruktor
};

// Klasa podstawowa robota
class RobotPodstawowy : public Robot {
public:
    void operacja() override {
        std::cout << "Robot podstawowy porusza się." << std::endl;
    }
};

// Klasa abstrakcyjna RobotDekorator
class RobotDekorator : public Robot {
protected:
    Robot* robot;  // Wskaźnik do obiektu typu Robot

public:
    RobotDekorator(Robot* r) : robot(r) {}
    virtual void operacja() override {
        robot->operacja();  // Wywołanie operacji robota dekorowanego
    }
    virtual ~RobotDekorator() = default;  // Usuwamy robot tylko w mainie
};

// Klasa dekoratora - RobotZKamera
class RobotZKamera : public RobotDekorator {
public:
    RobotZKamera(Robot* r) : RobotDekorator(r) {}

    void operacja() override {
        robot->operacja();  // Wywołanie operacji bazowego robota
        std::cout << "Robot ma teraz kamerę, może nagrywać." << std::endl;
    }
};

// Klasa dekoratora - RobotZCzujnikiemTemperatury
class RobotZCzujnikiemTemperatury : public RobotDekorator {
public:
    RobotZCzujnikiemTemperatury(Robot* r) : RobotDekorator(r) {}

    void operacja() override {
        robot->operacja();  // Wywołanie operacji bazowego robota
        std::cout << "Robot ma teraz czujnik temperatury." << std::endl;
    }
};

// Klasa dekoratora - RobotZDzwiekiem
class RobotZDzwiekiem : public RobotDekorator {
public:
    RobotZDzwiekiem(Robot* r) : RobotDekorator(r) {}

    void operacja() override {
        robot->operacja();  // Wywołanie operacji bazowego robota
        std::cout << "Robot ma teraz system dźwiękowy." << std::endl;
    }
};

// Główna funkcja
int main() {
    // Tworzymy podstawowego robota
    Robot* robot = new RobotPodstawowy();
    robot->operacja();
    std::cout << std::endl;

    // Dodajemy kamerę do robota
    Robot* robotZKamera = new RobotZKamera(robot);
    robotZKamera->operacja();
    std::cout << std::endl;

    // Dodajemy czujnik temperatury
    Robot* robotZKameraICzujnikTemp = new RobotZCzujnikiemTemperatury(robotZKamera);
    robotZKameraICzujnikTemp->operacja();
    std::cout << std::endl;

    // Dodajemy system dźwiękowy
    Robot* robotZPelnaFunkcjonalnoscia = new RobotZDzwiekiem(robotZKameraICzujnikTemp);
    robotZPelnaFunkcjonalnoscia->operacja();
    
    // Zwolnienie pamięci
    delete robotZPelnaFunkcjonalnoscia;
    delete robotZKameraICzujnikTemp;
    delete robotZKamera;
    delete robot;

    return 0;
}

