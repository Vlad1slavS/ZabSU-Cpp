#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <algorithm> // Для std::min и std::max

class Character {
public:
    Character(std::string name, int health, int attack);

    virtual ~Character() = default;

    virtual void attack(Character& target) const;
    virtual void printStatus() const;

    int getHealth() const;
    std::string getName() const;
    void takeDamage(int damage);

    void setHealth(int health); // Новый сеттер
    void setAttack(int attack); // Новый сеттер

protected:

    const int MAX_HEALTH = 100; // Максимальное здоровье
    const int MAX_ATTACK = 50;  // Максимальная атака
    
    std::string name_;
    int health_;
    int attack_;


};

#endif // CHARACTER_H
