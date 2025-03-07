#include "CreatureUtils.cpp"

int main() {
    ActiveCreature* creature1 = new ActiveCreature("lion", "panthera", 1, "Healthy");
    addCreature(creature1);
    g_activeCreatures.push_back(creature1);
    saveData();

    return 0;
}