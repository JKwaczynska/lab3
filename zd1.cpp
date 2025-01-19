#include <iostream>
#include <cmath>

class RobotStary {
public:
    virtual void idzDo(double x, double y) {
        std::cout << "RobotStary idzie do: (" << x << ", " << y << ")\n";
    }
};

class RobotNowy {
public:
    void idzDo(double kat, double odleglosc) {
        std::cout << "RobotNowy idzie do: (" << kat << " stopni, " << odleglosc << ")\n";
    }
};

class AdapterRobota : public RobotStary {
private:
    RobotNowy robotNowy;

public:
    void idzDo(double x, double y) override {
        double odleglosc = sqrt(x * x + y * y);
        double kat = atan2(y, x) * 180.0 / M_PI; // Konwersja na stopnie
        robotNowy.idzDo(kat, odleglosc);
        std::cout << "Robot idzie do: (" << kat << " stopni, " << odleglosc << ")\n";
    }
};

int main() {
    AdapterRobota adapter;
    double x, y;
    std::cout << "Podaj współrzędne x i y: ";
    std::cin >> x >> y;
    adapter.idzDo(x, y);
    return 0;
}

