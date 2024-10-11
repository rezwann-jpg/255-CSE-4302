#include "Car.h"

Car::Car() : fuelLevel(0) { }

Car::Car(std::string make, std::string model, double fuelCapacity) : make(make), model(model), fuelCapacity(fuelCapacity), fuelLevel(0) {}

Car::~Car() { }

void Car::operator+(const double fuel) {
    if (fuel + this->fuelLevel >= fuelCapacity) {
        std::cout << "cannot add more fuel\n";
        return;
    }
    fuelLevel += fuel;
}

void Car::operator-(const double fuel) {
    if (this->fuelLevel - fuel <= 0) {
        std::cout << "cannot decrease more fuel\n";
        return;
    }
    fuelLevel -= fuel;
}

void Car::operator+=(const double fuel) {
    if (fuel + this->fuelLevel >= fuelCapacity) {
        std::cout << "cannot add more fuel\n";
        return;
    }
    fuelLevel += fuel;
}

bool Car::operator==(const Car &c2) const {
    return (this->make == c2.make) && (this->model == c2.model) && (this->fuelCapacity == c2.fuelCapacity);
}

bool Car::operator<(const Car &c2) const {
    return this->fuelLevel < c2.fuelLevel;
}

bool Car::operator>(const Car &c2) const {
    return this->fuelLevel > c2.fuelLevel;
}

std::ostream &operator<<(std::ostream &os, const Car &c1) {
    os << "Car make: " << c1.make << std::endl 
    << "Car model: " << c1.model << std::endl 
    << "Fuel Capacity: " << c1.fuelCapacity << std::endl
    << "Current Fuel level: " << c1.fuelLevel << std::endl; 

    return os;
}

std::istream &operator>>(std::istream &is, Car &c1) {
    std::cout << "Enter Car make: ";
    is >> c1.make;
    std::cout << "Enter Model: ";
    is >> c1.model;
    std::cout << "Enter fuel Capacity: ";
    is >> c1.fuelCapacity;
    std::cout << "Enter Current fuel: ";
    is >> c1.fuelLevel;

    return is;
}