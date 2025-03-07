#include "RecoveringCreature.h"
#include <iostream>

RecoveringCreature::RecoveringCreature() {}

RecoveringCreature::RecoveringCreature(string name, string species, int id) : Creature(name, species, id) {}

RecoveringCreature::~RecoveringCreature() {}

void RecoveringCreature::addRecoveryStatus(string status) {
    m_recoveryStatus.insert(status);
}

void RecoveringCreature::displayDetails() const {
    Creature::displayDetails();
    cout << "Recovery Status: ";
    for (auto it = m_recoveryStatus.begin(); it != m_recoveryStatus.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
