/*
    Object Oriented Programming in C++
    Robert Lafore
    Chapter 4 Exercise 8

    Md. Rezwan Azam
    220041255
    CSE - 2A
*/

#include <iostream>

struct fraction {
    int numerator;
    int denominator;
};

int main() {
    fraction a, b, ans;
    char dummyCh;

    std::cout << "Enter first fraction: ";
    std::cin >> a.numerator >> dummyCh >> a.denominator;                        // Same mistake happen agian
    std::cout << "Enter second fraction: ";                                     // my bad
    std::cin >> b.numerator >> dummyCh >> b.denominator;

    ans.numerator = a.numerator * b.denominator + b.numerator + a.denominator;
    ans.denominator = a.denominator * b.denominator;

    std::cout << "Sum: " << ans.numerator << "/" << ans.denominator << std::endl;

    return 0;
}