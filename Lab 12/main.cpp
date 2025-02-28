#include "Sanctuary.h"
#include <iostream>

using namespace std;

int main() {
    Sanctuary sanctuary;
    int choice;

    do {
        cout << "\nSanctuary Management System\n";
        cout << "1. Add Creature\n";
        cout << "2. Send to Recovery\n";
        cout << "3. Return from Recovery\n";
        cout << "4. Release Creature\n";
        cout << "5. Display Creatures\n";
        cout << "6. Save Data\n";
        cout << "7. Load Data\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                sanctuary.addCreature();
                break;
            case 2:
                sanctuary.sendToRecovery();
                break;
            case 3:
                sanctuary.returnFromRecovery();
                break;
            case 4:
                sanctuary.releaseCreature();
                break;
            case 5:
                sanctuary.displayCreatures();
                break;
            case 6:
                sanctuary.saveData();
                break;
            case 7:
                sanctuary.loadData();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);
}