#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

// Класс для персонажа типа Воин.
// Добавляет характеристики: защита и выносливость.
class Warrior : public Character {
public:
    // Конструктор
    Warrior(std::string name, int health, int attack, int defense, int stamina);

    // Переопределение метода атаки
    void attack(Character& target) const override;

    // Выводит статус воина на экран
    void printStatus() const override;

    // Сеттеры для ограниченной установки значений (не больше максимальных значений)
    void setDefense(int defense);
    void setStamina(int stamina);

private:
    int defense_; // Защита воина
    int stamina_; // Выносливость воина

    // Максимальные значения защиты и выносливости
    static const int MAX_DEFENSE;
    static const int MAX_STAMINA;
};

#endif // WARRIOR_H
