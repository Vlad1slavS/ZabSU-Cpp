#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
public:
    Warrior(std::string name, int health, int attack, int defense, int stamina);

    void attack(Character& target) const override;
    void printStatus() const override;

    void setDefense(int defense); // Новый сеттер
    void setStamina(int stamina); // Новый сеттер

private:

    const int MAX_DEFENSE = 20;     // Максимальная защита
    const int MAX_STAMINA = 100;    // Максимальная выносливость

    
    int defense_;
    int stamina_;
};

#endif // WARRIOR_H
