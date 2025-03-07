#ifndef CREATURE_H
#define CREATURE_H

#pragma once

#include <string>

using namespace std;

class Creature {
public:
    Creature();
    Creature(string name, string species, int id);
    ~Creature();

    string getName() const;
    string getSpecies() const;
    int getId() const;

    virtual void displayDetails() const;

protected:
    string m_name;
    string m_species;
    int m_id;

};

#endif