#include <iostream>

class Temperature {
private:
    int temp;
    int incrementStep;

public:
    Temperature();
    void setIncrementStep(int step);
    int getTemperature();
    void increment();
    void resetTemperature();
};

Temperature::Temperature() {
    temp = 0;
    incrementStep = 0;
}

void Temperature::setIncrementStep(int step) {
    incrementStep = step;
}

int Temperature::getTemperature() {
    return temp;
}

void Temperature::increment() {
    temp += incrementStep;
}

void Temperature::resetTemperature() {
    temp = 0;
}

int main() {
    Temperature t;
    t.setIncrementStep(2);
    t.increment();

    std::cout << "Temp: " << t.getTemperature() << std::endl;

    t.resetTemperature();

    std::cout << "Temp: " << t.getTemperature() << std::endl;

    return 0;
}