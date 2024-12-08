#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character {
public:
    Mage(std::string name, int health, int attack, int mana);

    void attack(Character& target) const override;
    void printStatus() const override;

    int getMana() const;
    void setMana(int mana); // Новый сеттер

private:
    const int MAX_MANA = 100; // Максимальная мана
    
    int mana_;
};

#endif // MAGE_H
