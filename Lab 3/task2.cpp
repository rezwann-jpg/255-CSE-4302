#include <iostream>
#include <iomanip>

class RationalNumber {
private:
    int numerator;
    int denominator;
    bool flag;

public:
    RationalNumber() {
        flag = false;
    }
    void assign(int numerator, int denominator);
    float convert();
    void invert();
    void print();
};

void RationalNumber::assign(int numerator, int denominator) {
    this->numerator = numerator;
    if (denominator == 0) {
        std::cout << "You can not assign 0 as denominator." << std::endl;
        flag = true;
        return;
    }
    else {
        this->denominator = denominator;
        flag = false;
    }
}

float RationalNumber::convert() {
    if (flag) {
        return 0;
    }
    return (float)numerator / denominator;
}

void RationalNumber::invert() {
    if (numerator == 0) {
        std::cout << "You can not assign 0 as denominator. Inversion Failed. " << std::endl;
        return;
    }

    int temp = numerator;
    numerator = denominator;
    denominator = temp;
}

void RationalNumber::print() {
    if (flag) {
        std::cout << "Valid input has not been given" << std::endl;
    }
    else {
        std::cout << "The Rational Number is " << numerator << "/" << denominator << std::endl;
    }
}

int main() {
    RationalNumber r1;
    r1.assign(2, 3);
    r1.print();

    std::cout << std::setprecision(5);
    std::cout << "Decimal equivalent: " << r1.convert() << std::endl;

    r1.invert();

    // std::cout << std::setprecision(5);
    std::cout << "Decimal equivalent: " << r1.convert() << std::endl;

    r1.print();

    return 0;
}