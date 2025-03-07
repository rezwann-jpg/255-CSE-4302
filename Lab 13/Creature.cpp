#include "Creature.h"
#include <iostream>

Creature::Creature() {}

Creature::Creature(string name, string species, int id) : m_name(name), m_species(species), m_id(id) {}

Creature::~Creature() {}

string Creature::getName() const {
    return m_name;
}

string Creature::getSpecies() const {
    return m_species;
}

int Creature::getId() const {
    return m_id;
}

void Creature::displayDetails() const {
    cout << "Name: " << m_name << endl;
    cout << "Species: " << m_species << endl;
    cout << "ID: " << m_id << endl;
}
