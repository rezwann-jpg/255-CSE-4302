#include "Creature.h"
#include <iostream>

Creature::Creature() {}

Creature::Creature(const string &name, const string &species, const string &healthStatus, int age) : 
                m_name(name), m_species(species), m_healthStatus(healthStatus), m_age(age) {
    
    
}


Creature::~Creature() {}

string Creature::getName() const {
    return m_name;
}

string Creature::getSpecies() const {
    return m_species;
}

string Creature::getHealthStatus() const {
    return m_healthStatus;
}

int Creature::getAge() const {
    return m_age;
}

void Creature::setName(const string &name) {
    m_name = name;
}

void Creature::setSpecies(const string &species) {
    m_species = species;
}

void Creature::setHealthStatus(const string &healthStatus) {
    m_healthStatus = healthStatus;
}

void Creature::setAge(int age) {
    m_age = age;
}

void Creature::displayDetailes() const {
    cout << "Name: " << m_name << endl;
    cout << "Species: " << m_species << endl;
    cout << "Health Status: " << m_healthStatus << endl;
    cout << "Age: " << m_age << endl;
}