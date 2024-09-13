/*
    Object Oriented Programming in C++
    Robert Lafore
    Chapter 6 Exercise 6

    Md. Rezwan Azam
    220041255
    CSE - 2A
*/

#include <iostream>

enum etype { 
    laborer, 
    secretary, 
    manager, 
    accountant, 
    executive,
    researcher 
};

int main() {
    char chocie;

    std::cout << "Enter employee type (first letter only)\n laborer, secretary, manager,\n accountant, executive, researcher): ";
    std::cin >> chocie;

    int selectedEmployee;

    switch (chocie) {
    case 'l':
        selectedEmployee = laborer;
        break;
    case 's':
        selectedEmployee = secretary;
        break;
    case 'm':
        selectedEmployee = manager;
        break;
    case 'a':
        selectedEmployee = accountant;
        break;
    case 'e':
        selectedEmployee = executive;
        break;
    case 'r':
        selectedEmployee = researcher;
        break;
    
    default:
        break;
    }

    switch (selectedEmployee) {
    case laborer:
        std::cout << "Employee type is laborer" << std::endl;
        break;
    case secretary:
        std::cout << "Employee type is secretary" << std::endl;
        break;
    case manager:
        std::cout << "Employee type is manager" << std::endl;
        break;
    case accountant:
        std::cout << "Employee type is accountant" << std::endl;
        break;
    case executive:
        std::cout << "Employee type is executive" << std::endl;
        break;
    case researcher:
        std::cout << "Employee type is reseacher" << std::endl;
        break;
    
    default:
        break;
    }
}