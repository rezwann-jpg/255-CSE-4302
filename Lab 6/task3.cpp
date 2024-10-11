#include <iostream>

class Celsius;
class Farenheit;
class Kelvin;

class Celsius {
public:
    Celsius() { }
    Celsius(double temp = 0) {
        temperature = temp >= -273.15 ? temp : -273.15;
    }
    void assign(double temp) {
        temperature = temp >= -273.15 ? temp : -273.15;
    }
    void display() {
        std::cout << "The temperature is " << temperature << " Celsius.\n";
    }
    operator Farenheit() const;
    operator Kelvin() const;
private:
    double temperature;
};

Celsius::operator Farenheit() const {
    return Farenheit((temperature * 9.0) / 5.0 + 32);
}

Celsius::operator Kelvin() const {
    return Kelvin(temperature + 273.15);
}


class Farenheit {
public:
    Farenheit() { }
    Farenheit(double temp = 0) {
        temperature = temp >= -459.67 ? temp : -459.67;
    }
    void assign(double temp) {
        temperature = temp >= -273.15 ? temp : -273.15;
    }
    void display() {
        std::cout << "The temperature is " << temperature << " Celsius.\n";
    }
    operator Celsius() const;
    operator Kelvin() const {
        return Kelvin((5 / 9) * temperature + 459.67);
    }
private:
    double temperature;
};

Farenheit::operator Celsius const {
    return Celsius(((temperature - 32) * 5) / 9);
}

class Kelvin {
public:
    Kelvin() { }
    Kelvin(double temp = 0) {
        temperature = temp >= 0.0 ? temp : 0.0;
    }
    void assign(double temp) {
        temperature = temp >= 0.0 ? temp : 0.0;
    }
    void display() {
        std::cout << "The temperature is " << temperature << " Celsius.\n";
    }
    operator Celsius() const {
        return Celsius(temperature - 273.15);
    }
    operator Farenheit() const {
        return Kelvin((temperature - 273.15) * (9 / 5) + 32);
    }
private:
    double temperature;
};



int main() {

}
