#include "Mage.h"

// Определение статической константы
const int Mage::MAX_MANA = 100;

Mage::Mage(std::string name, int health, int attack, int mana)
    : Character(name, health, attack), mana_(std::max(0, std::min(mana, MAX_MANA))) {}

void Mage::attack(Character& target) const {
    int damage = attack_ + mana_ / 10; // Бонус к атаке в зависимости от маны
    target.takeDamage(damage);
    std::cout << name_ << " (Маг) атаковал " << target.getName() 
              << ", нанеся " << damage << " урона!" << std::endl;
    std::cout << target.getName() << " осталось " << target.getHealth() 
              << " здоровья." << std::endl;
}

void Mage::printStatus() const {
    std::cout << "Имя: " << name_ 
              << ", Здоровье: " << health_ 
              << ", Атака: " << attack_ 
              << ", Мана: " << mana_ << std::endl;
}

int Mage::getMana() const { return mana_; }

void Mage::setMana(int mana) {
    mana_ = std::max(0, std::min(mana, MAX_MANA));
}
