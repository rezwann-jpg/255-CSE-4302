#include "ActiveCreature.h"
#include <iostream>

ActiveCreature::ActiveCreature() {}

ActiveCreature::ActiveCreature(string name, string species, int id, string healthStatus) : Creature(name, species, id), m_healthStatus(healthStatus) {}

ActiveCreature::~ActiveCreature() {}

string ActiveCreature::getHealthStatus() const {
    return m_healthStatus;
}

void ActiveCreature::setHealthStatus(string healthStatus) {
    m_healthStatus = healthStatus;
}

void ActiveCreature::addDailyActivity(string activity) {
    m_dailyActivites.insert(activity);
}

const set<string> &ActiveCreature::getDailyActivities() const {
    return m_dailyActivites;
}

void ActiveCreature::displayDetails() const {
    Creature::displayDetails();
    cout << "Health Status: " << m_healthStatus << endl;
    cout << "Daily Activities: ";
    for (auto it = m_dailyActivites.begin(); it != m_dailyActivites.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

}
