#ifndef RECOVERINGCREATURE_H
#define RECOVERINGCREATURE_H

#pragma once

#include "Creature.h"
#include <set>

using namespace std;

class RecoveringCreature : public Creature {
public:
    RecoveringCreature();
    RecoveringCreature(string name, string species, int id);
    ~RecoveringCreature();

    void addRecoveryStatus(string status);
    void displayDetails() const override;

private:
    set<string> m_recoveryStatus;
};

#endif