// Автор: Степанов Владислав ИВТ-23

#include "Warrior/Warrior.h"
#include "Mage/Mage.h"

int main() {
    try
    {
        // Создание персонажей
        Warrior warrior("Валентин", 100, 15, 5, 20);
        Mage mage("Агния", 80, 20, 50);

        // Вывод начального статуса
        warrior.printStatus();
        mage.printStatus();

        // Атаки и обновление статуса
        warrior.attack(mage);
        mage.attack(warrior);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return 0;
}
