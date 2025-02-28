#include "Sanctuary.h"
#include <string>
#include <iostream>
#include <fstream>

Sanctuary::Sanctuary() {}

Sanctuary::~Sanctuary() {}

void Sanctuary::addCreature() {
    string name, species, healthStatus;
    int age;
    cout << "Enter Creature Name: ";
    cin >> name;
    cout << "Enter Creature Species: ";
    cin >> species;
    cout << "Enter Creature Health Status: ";
    cin >> healthStatus;
    cout << "Enter Creature Age: ";
    cin >> age;

    m_inhabitants.push_back(Creature(name, species, healthStatus, age));
}

void Sanctuary::sendToRecovery() {
    if (m_inhabitants.empty()) {
        cout << "No creatures in the sanctuary." << endl;
        return;
    }

    cout << "Select a creature to send to recovery: " << endl;
    for (int i = 0; i < m_inhabitants.size(); i++) {
        cout << i + 1 << ". " << m_inhabitants[i].getName() << " (" << m_inhabitants[i].getSpecies() << ")" << endl;
    }

    int choice;
    cout << "Enter the number of the creature you want to send to recovery: ";
    cin >> choice;

    if (choice < 1 || choice > m_inhabitants.size()) {
        cout << "Invalid choice." << endl;
        return;
    }
    
    Creature creature = m_inhabitants[choice - 1];
    if (creature.getHealthStatus() == "Injured" || creature.getHealthStatus() == "Resting") {
        m_recoveryZone.push_back(creature);
        m_inhabitants.erase(m_inhabitants.begin() + choice - 1);
    }
    else {
        cout << "Creature is already healthy" << endl;
    }
}

void Sanctuary::returnFromRecovery() {
    if (m_recoveryZone.empty()) {
        cout << "No creatures in the recovery zone." << endl;
        return;
    }

    cout << "Select a creature to return from recovery: " << endl;
    for (int i = 0; i < m_recoveryZone.size(); i++) {
        cout << i + 1 << ". " << m_recoveryZone[i].getName() << " (" << m_recoveryZone[i].getSpecies() << ")" << endl;
    }

    int choice;
    cout << "Enter the number of the creature you want to return from recovery: ";
    cin >> choice;

    if (choice < 1 || choice > m_recoveryZone.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    Creature creature = m_recoveryZone[choice - 1];
    creature.setHealthStatus("Healthy");
    m_inhabitants.push_back(creature);
    m_recoveryZone.erase(m_recoveryZone.begin() + choice - 1);
}

void Sanctuary::releaseCreature() {
    if (m_inhabitants.empty()) {
        cout << "No creatures in the sanctuary." << endl;
        return;
    }

    cout << "Select a creature to release: " << endl;
    for (int i = 0; i < m_inhabitants.size(); i++) {
        cout << i + 1 << ". " << m_inhabitants[i].getName() << " (" << m_inhabitants[i].getSpecies() << ")" << endl;
    }

    int choice;
    cout << "Enter the number of the creature you want to release: ";
    cin >> choice;

    if (choice < 1 || choice > m_inhabitants.size()) {
        cout << "Invalid choice." << endl;
        return;
    }
    
    Creature creature = m_inhabitants[choice - 1];
    if (creature.getHealthStatus() == "Healthy") {
        m_releasedCreature.push_back(creature);
        m_inhabitants.erase(m_inhabitants.begin() + choice - 1);
    }
    else {
        cout << "Creature is not healthy enough to be released." << endl;
    }
}

void Sanctuary::displayCreatures() const {
    displayInhabitants();
    displayRecoveryZone();
    displayReleased();
}

void Sanctuary::saveData() {
    ofstream inhabitantsFile("inhabitants.txt");
    ofstream recoveryFile("recovery.txt");
    ofstream releasedFile("released.txt");
    if (!inhabitantsFile || !recoveryFile || !releasedFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const auto& creature : m_inhabitants) {
        inhabitantsFile << creature.getName() << "," << creature.getSpecies() << "," << creature.getHealthStatus() << "," << creature.getAge() << endl;
    }
    for (const auto& creature : m_recoveryZone) {
        recoveryFile << creature.getName() << "," << creature.getSpecies() << "," << creature.getHealthStatus() << "," << creature.getAge() << endl;
    }
    for (const auto& creature : m_releasedCreature) {
        releasedFile << creature.getName() << "," << creature.getSpecies() << "," << creature.getHealthStatus() << "," << creature.getAge() << endl;
    }

    cout << "Data saved successfully." << endl;

    inhabitantsFile.close();
    recoveryFile.close();
    releasedFile.close();
}

void Sanctuary::loadData() {
    ifstream inhabitantsFile("inhabitants.txt");
    ifstream recoveryFile("recovery.txt");
    ifstream releasedFile("released.txt");
    if (!inhabitantsFile || !recoveryFile || !releasedFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    string line;
    while (getline(inhabitantsFile, line)) {
        m_inhabitants.push_back(strParser(line));
    }

    while (std::getline(recoveryFile, line)) {
        m_recoveryZone.push_back(strParser(line));
    }

    while (std::getline(releasedFile, line)) {
        m_releasedCreature.push_back(strParser(line));
    }

    inhabitantsFile.close();
    recoveryFile.close();
    releasedFile.close();
}

void Sanctuary::displayInhabitants() const {
    if (m_inhabitants.empty()) {
        cout << "No creatures in the sanctuary." << endl;
    }
    else {
        cout << "Inhabitants of the sanctuary:" << endl;
        for (const auto& creature : m_inhabitants) {
            creature.displayDetailes();
            cout << "--------------------------\n";
        }
    }
}

void Sanctuary::displayRecoveryZone() const {
    if (m_recoveryZone.empty()) {
        cout << "No creatures in the recovery zone." << endl;
    }
    else {
        cout << "Creatures in the recovery zone:" << endl;
        for (const auto& creature : m_recoveryZone) {
            creature.displayDetailes();
            cout << "--------------------------\n";
        }
    }
}

void Sanctuary::displayReleased() const {
    if (m_releasedCreature.empty()) {
        cout << "No creatures have been released." << endl;
    }
    else {
        cout << "Creatures that have been released:" << endl;
        for (const auto& creature : m_releasedCreature) {
            creature.displayDetailes();
            cout << "--------------------------\n";
        }
    }
}

Creature strParser(const string &str) {
    string name, species, healthStatus;
    int age;
    size_t pos1 = str.find(',');
    size_t pos2 = str.find(',', pos1 + 1);
    size_t pos3 = str.find(',', pos2 + 1);
    name = str.substr(0, pos1);
    species = str.substr(pos1 + 1, pos2 - pos1 - 1);
    healthStatus = str.substr(pos2 + 1, pos3 - pos2 - 1);
    age = stoi(str.substr(pos3 + 1));
    return Creature(name, species, healthStatus, age);
}
