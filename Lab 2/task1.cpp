/*
    Object Oriented Programming in C++
    Robert Lafore
    Chapter 2 Exercise 9

    Md. Rezwan Azam
    220041255
    CSE - 2A
*/

#include <iostream>

int main() {
    char dummyChar;
    int a, b, c, d;

    std::cout << "Enter first fraction: ";                          //  I forgot to check if the denom was                                   
    std::cin >> a >>  dummyChar >> b;                               //  zero or not
    std::cout << "Enter second fraction: ";                         //  my bad. won't happen again
    std::cin >> c >> dummyChar >> d;                                //  

    std::cout << "Sum: ";
    std::cout << a * d + b * c << "/" << b * d << std::endl;

    return 0;
}