#ifndef CREATURE_H
#define CREATURE_H

#pragma once

#include <string>

using namespace std;

class Creature {
public:
    Creature();
    Creature(const string& name, const string& species, const string& healthStatus, int age);
    ~Creature();

    string getName() const;
    string getSpecies() const;
    string getHealthStatus() const;
    int getAge() const;

    void setName(const string& name);
    void setSpecies(const string& species);
    void setHealthStatus(const string& healthStatus);
    void setAge(int age);

    void displayDetailes() const;
private:
    string m_name;
    string m_species;
    string m_healthStatus;
    int m_age;
};

#endif