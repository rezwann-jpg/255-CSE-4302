#ifndef CAR_H
#define CAR_H

#pragma once

#include <string>
#include <iostream>

class Car {
public:
    Car();
    Car(std::string make, std::string model, double fuelCapacity);
    ~Car();

    void operator +(const double fuel);
    void operator -(const double fuel);
    void operator +=(const double fuel);
    bool operator ==(const Car& c2) const;
    bool operator <(const Car& c2) const;
    bool operator >(const Car& c2) const;

    friend std::ostream& operator<<(std::ostream& os, const Car& c1);
    friend std::istream& operator>>(std::istream& is, Car& c1);
private:
    std::string make;
    std::string model;
    double fuelCapacity;
    double fuelLevel;
};

#endif