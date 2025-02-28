#ifndef SANCTUARY_H
#define SANCTUARY_H

#pragma once

#include <vector>
#include <deque>
#include <list>
#include "Creature.h"

using namespace std;

class Sanctuary {
public:
    Sanctuary();
    ~Sanctuary();

    void addCreature();
    void sendToRecovery();
    void returnFromRecovery();
    void releaseCreature();
    void displayCreatures() const;
    void saveData();
    void loadData();

private:
    void displayInhabitants() const;
    void displayRecoveryZone() const;
    void displayReleased() const;

    vector<Creature> m_inhabitants;
    deque<Creature> m_recoveryZone;
    list<Creature> m_releasedCreature;

};

Creature strParser(const string& str);

#endif