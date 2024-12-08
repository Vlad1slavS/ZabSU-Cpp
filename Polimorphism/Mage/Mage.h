#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

// Класс для персонажа типа Маг.
// Добавляет характеристику: мана.
class Mage : public Character {
public:
    // Конструктор
    Mage(std::string name, int health, int attack, int mana);

    // Переопределение метода атаки
    void attack(Character& target) const override;

    // Выводит статус мага на экран
    void printStatus() const override;

    // Геттер маны и сеттер
    int getMana() const;
    void setMana(int mana);

private:
    // Максимальное значение маны
    static const int MAX_MANA;

    int mana_; // Мана мага

};

#endif // MAGE_H
