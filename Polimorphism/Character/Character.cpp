#include "Character.h"


Character::Character(std::string name, int health, int attack)
    : name_(name), health_(std::max(0, std::min(health, MAX_HEALTH))), attack_(std::max(0, std::min(attack, MAX_ATTACK))) {}

void Character::attack(Character& target) const {
    int damage = attack_;
    target.takeDamage(damage);
    std::cout << name_ << " атаковал " << target.getName() 
              << ", нанеся " << damage << " урона!" << std::endl;
    std::cout << target.getName() << " осталось " << target.getHealth() 
              << " здоровья." << std::endl;
}

void Character::printStatus() const {
    std::cout << "Имя: " << name_ 
              << ", Здоровье: " << health_ 
              << ", Атака: " << attack_ << std::endl;
}

int Character::getHealth() const {
    return health_;
}

std::string Character::getName() const {
    return name_;
}

void Character::takeDamage(int damage) {
    setHealth(health_ - damage);
}

void Character::setHealth(int health) {
    health_ = std::max(0, std::min(health, MAX_HEALTH));
}

void Character::setAttack(int attack) {
    attack_ = std::max(0, std::min(attack, MAX_ATTACK));
}
