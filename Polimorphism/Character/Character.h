#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <algorithm> // Для std::min и std::max

// Базовый класс для всех персонажей. 
// Содержит основные характеристики: имя, здоровье и атака.
class Character {
public:
    // Конструктор
    Character(std::string name, int health, int attack);

    // Виртуальный деструктор
    virtual ~Character() = default; // default деструктор нызывается, когда объект выходит из области видимости или явно удаляется

    // Атака, которая наносит урон цели
    virtual void attack(Character& target) const;

    // Вывод статуса персонажа на экран
    virtual void printStatus() const;

    // Геттеры
    int getHealth() const;
    std::string getName() const;

    // Уменьшает здоровье на указанное количество урона damage
    void takeDamage(int damage);

    // Сеттеры для ограниченной установки значений
    void setHealth(uint health);
    void setAttack(uint attack);

protected:
    // Максимальные значения характеристик
    static const int MAX_HEALTH; 
    static const int MAX_ATTACK;

    std::string name_; // Имя персонажа
    int health_;       // Здоровье персонажа
    int attack_;       // Атака персонажа

};

#endif // CHARACTER_H
