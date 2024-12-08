#include "Warrior.h"
#include "Mage.h"

int main() {
    Warrior warrior("Валентин", 100, 15, 5, 20);
    Mage mage("Агния", 80, 20, 50);

    warrior.printStatus();
    mage.printStatus();

    warrior.attack(mage);
    mage.attack(warrior);

    return 0;
}
