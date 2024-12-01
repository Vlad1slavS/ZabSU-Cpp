#include <string>
#include <iostream>
#include "Character.cpp"
#include "Warrior.cpp"
#include "Mage.cpp"


// Пример использования:
int main() {
    Warrior warrior("Воин", 100, 15, 5, 50);
    Mage mage("Маг", 80, 10, 100);

    warrior.printStatus();
    mage.printStatus();

    std::cout << std::endl;
    warrior.attack(mage);
    mage.attack(warrior);

    return 0;
}
