#include "Warrior.h"

// Определения статических констант
const int Warrior::MAX_DEFENSE = 20;
const int Warrior::MAX_STAMINA = 100;

Warrior::Warrior(std::string name, int health, int attack, int defense, int stamina)
    : Character(name, health, attack), defense_(std::max(0, std::min(defense, MAX_DEFENSE))), stamina_(std::max(0, std::min(stamina, MAX_STAMINA))) {}

void Warrior::attack(Character& target) const {
    int damage = attack_ + 5; // Бонус к атаке
    target.takeDamage(damage);
    std::cout << name_ << " (Воин) атаковал " << target.getName() 
              << ", нанеся " << damage << " урона!" << std::endl;
    std::cout << target.getName() << " осталось " << target.getHealth() 
              << " здоровья." << std::endl;
}

void Warrior::printStatus() const {
    std::cout << "Имя: " << name_ 
              << ", Здоровье: " << health_ 
              << ", Атака: " << attack_ 
              << ", Защита: " << defense_ 
              << ", Выносливость: " << stamina_ << std::endl;
}

void Warrior::setDefense(int defense) {
    defense_ = std::max(0, std::min(defense, MAX_DEFENSE));
}

void Warrior::setStamina(int stamina) {
    stamina_ = std::max(0, std::min(stamina, MAX_STAMINA));
}
