#include <iostream>
#include <string>

#define DISTANCE 100
const float PETROL_PRICE = 0.89f;
const float DIESEL_PRICE = 3.24f;
const float HYBRID_PRICE = 2.45f;

enum fuelType {
    Petrol,
    Diesel,
    Electric,
    Hybrid            
};

class Car {
public:
    Car(int x);
    void DisplayInfo();
    void SetCar();

private:
    float GetFuelCost();
    int GetFuelConsumption();
    bool isFuelEfficient();

    std::string brandName;
    std::string modelName;
    int makeYear;
    fuelType ftype;
    int milage;
    int carID;
};

Car::Car(int x) {
    carID = x;
}

void Car::DisplayInfo() {
    std::cout << "Car: " << carID << std::endl;
    std::cout << "Brand: " << brandName << std::endl;
    std::cout << "Model: " << modelName << std::endl;
    std::cout << "Year: " << makeYear << std::endl;
    std::cout << "Feul Type: ";

    switch (ftype) {
        case Petrol:
            std::cout << "Petrol" << std::endl;
            break;
        case Diesel:
            std::cout << "Diesel" << std::endl;
            break;
        case Hybrid:
            std::cout << "Hybrid" << std::endl;
            break;
        case Electric:
            std::cout << "Electric" << std::endl;
            break;
    }

    std::cout << "Milage: " << milage << std::endl;

    if (isFuelEfficient())
        std::cout << "The car is fuel-efficient" << std::endl;
    else 
        std::cout << "The car is not fuel-efficient" << std::endl;

    if (ftype != Electric)
        std::cout << "Estimated fuel cost for 100 km: " << GetFuelCost() << std::endl; 
    else
        std::cout << "This car is electric, efficiency measured in km/charge." << std::endl;
}

void Car::SetCar() {
    std::cout << "Brand: ";
    std::cin >> brandName;
    std::cin.ignore();
    std::cout << "Model: ";
    std::getline(std::cin, modelName);
    std::cout << "Year: ";
    std::cin >> makeYear;
    std::cout << "Fuel Type (Petrol, Diesel, Electric, Hybrid) Input fisrt letter: ";
    char ch;
    std::cin >> ch;

    switch (ch) {
    case 'p':
        ftype = Petrol;
        break;
    case 'd':
        ftype = Diesel;
        break;
    case 'e':
        ftype = Electric;
        break;
    case 'h':
        ftype = Hybrid;
        break;
    
    default:
        break;
    }

    std::cout << "Milage: ";
    std::cin >> milage;
}

float Car::GetFuelCost() {
    if (ftype == Petrol)
        return (DISTANCE / milage) * PETROL_PRICE;
    else if (ftype == Diesel)
        return (DISTANCE / milage) * DIESEL_PRICE;
    else if (ftype == Hybrid)
        return (DISTANCE / milage) * HYBRID_PRICE;

    return 0;
}

int Car::GetFuelConsumption() {
    return DISTANCE / milage;
}

bool Car::isFuelEfficient()
{
    return milage > 15;
}

int main() {
    Car cars[4] = { 1, 2, 3, 4 };

    for (int i = 0; i < 4; i++) {
        cars[i].SetCar();
    }

    for (int i = 0; i < 4; i++) {
        cars[i].DisplayInfo();
    }

    return 0;
}