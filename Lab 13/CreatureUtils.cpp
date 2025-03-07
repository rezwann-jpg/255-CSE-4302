#include "Creature.h"
#include "ActiveCreature.h"
#include "RecoveringCreature.h"
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

map<int, string> g_creatureMap;
vector<Creature*> g_activeCreatures;
vector<Creature*> g_recoveringCreature;

void addCreature(Creature* pCreature) {
    g_creatureMap[pCreature->getId()] = pCreature->getName();
}

void sendToRecovery(int id) {
    for (auto& creature : g_activeCreatures) {
        if (creature->getId() == id) {
            if (dynamic_cast<ActiveCreature*>(creature)->getHealthStatus() != "Healthy") {
                g_recoveringCreature.push_back(dynamic_cast<RecoveringCreature*>(creature));
                g_activeCreatures.erase(remove(g_activeCreatures.begin(), g_activeCreatures.end(), creature), g_activeCreatures.end());
                g_creatureMap.erase(id);
                cout << "Creature " << creature->getName() << " has been sent to recovery." << endl;
                return;
            }
            else {
                cout << "Creature " << creature->getName() << " is healthy and does not need to be sent to recovery." << endl;
            }
        }
    }

    cout << "Creature with id " << id << " not found." << endl;
}

void performDailyActivity(int id) {
    for (auto& creature : g_activeCreatures) {
        if (creature->getId() == id) {
            if (creature->getName() != "") {
                string activity;
                cout << "Enter Daily Activity for " << creature->getName() << ": ";
                cin >> activity;
                dynamic_cast<ActiveCreature*>(creature)->addDailyActivity(activity);
                if (dynamic_cast<ActiveCreature*>(creature)->getDailyActivities().size() > 3) {
                    dynamic_cast<ActiveCreature*>(creature)->setHealthStatus("Tired");
                }
                cout << "Daily Activity added for " << creature->getName() << endl;
                return;
            }
        }
    }

    cout << "Creature with id " << id << " not found." << endl;
}

void returnFromRecovery(int id) {
    for (auto& creature : g_recoveringCreature) {
        if (creature->getId() == id) {
            dynamic_cast<ActiveCreature*>(creature)->setHealthStatus("Healthy");
            g_activeCreatures.push_back(dynamic_cast<ActiveCreature*>(creature));
            g_recoveringCreature.erase(remove(g_recoveringCreature.begin(), g_recoveringCreature.end(), creature), g_recoveringCreature.end());
            g_creatureMap[id] = creature->getName();
            cout << "Creature " << creature->getName() << " has returned from recovery." << endl;
            return;
        }
    }
    
    cout << "Creature with id " << id << " not found." << endl;
}

void releaseCreature(int id) {
    for (auto& creature : g_activeCreatures) {
        if (creature->getId() == id) {
            if (dynamic_cast<ActiveCreature*>(creature)->getHealthStatus() != "Healthy") {
                g_activeCreatures.erase(remove(g_activeCreatures.begin(), g_activeCreatures.end(), creature), g_activeCreatures.end());
                g_creatureMap.erase(id);
                cout << "Creature " << creature->getName() << " has been released." << endl;
                return;
            }
        }
    }
    std::cout << "Creature not found in recovery." << std::endl;

}

void saveData() {
    ofstream activeFile("active_creatures.txt");
    ofstream recoveryFile("recovery_creatures.txt");

    if (!activeFile || !recoveryFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const auto& creature : g_activeCreatures) {
        ActiveCreature* creature1 = dynamic_cast<ActiveCreature*>(creature);
        activeFile << creature1->getId() << " " << creature1->getName() << " " << creature1->getSpecies() << " " << creature1->getHealthStatus() << endl;
    }

    for (const auto& creature : g_recoveringCreature) {
        RecoveringCreature* creature1 = dynamic_cast<RecoveringCreature*>(creature);
        recoveryFile << creature1->getId() << " " << creature1->getName() << " " << creature1->getSpecies() << endl;
    }

    activeFile.close();
    recoveryFile.close();
}

void loadData() {
    ifstream activeFile("active_creatures.txt");
    ifstream recoveryFile("recovery_creatures.txt");

    if (!activeFile || !recoveryFile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    int id;
    string name, species, healthStatus;

    while (activeFile >> id >> name >> species >> healthStatus) {
        g_activeCreatures.push_back(new ActiveCreature(name, species, id, healthStatus));
        g_creatureMap[id] = name;
    }

    while (recoveryFile >> id >> name >> species) {
        g_recoveringCreature.push_back(new RecoveringCreature(name, species, id));
    }

    activeFile.close();
    recoveryFile.close();
}
