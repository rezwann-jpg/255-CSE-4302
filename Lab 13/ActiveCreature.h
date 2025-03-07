#ifndef ACTIVECREATURE_H
#define ACTIVECREATURE_H

#pragma once

#include "Creature.h"
#include <set>

using namespace std;

class ActiveCreature : public Creature {
public:
    ActiveCreature();
    ActiveCreature(string name, string species, int id, string healthStatus);
    ~ActiveCreature();

    string getHealthStatus() const;
    void setHealthStatus(string healthStatus);
    void addDailyActivity(string activity);
    const set<string>& getDailyActivities() const;

    void displayDetails() const override;

private:
    string m_healthStatus;
    set<string> m_dailyActivites;
};

#endif