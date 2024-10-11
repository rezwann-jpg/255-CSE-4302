#include "Car.h"

int main() {
    Car c1("Toyota", "Corolla", 300.0);
    Car c2("Lexus", "LFA", 400.0);

    c1 + 15.0;

    c1 += 10.0;

    Car c3;

    std::cin >> c3;

    std::cout << c1 << c2 << c3;

    return 0; 
}