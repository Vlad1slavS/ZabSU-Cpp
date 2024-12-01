#include <iostream>
#include <string>

class Mage : public Character {
public:
    Mage(std::string name, int health, int attack, int mana)
        : Character(name, health, attack), mana_(mana) {}

    void attack(Character& target) const override {
        int damage = attack_ + mana_ / 10; // Бонус урона от маны
        target.takeDamage(damage);
        std::cout << name_ << " (Маг) атаковал " << target.getName() 
                  << ", нанеся " << damage << " урона!" << std::endl;
        std::cout << target.getName() << " осталось " << target.getHealth() 
                  << " здоровья." << std::endl;
    }

    void printStatus() const override {
        std::cout << "Имя: " << name_ 
                  << ", Здоровье: " << health_ 
                  << ", Атака: " << attack_ 
                  << ", Мана: " << mana_ << std::endl;
    }

    int getMana() const { return mana_; }

private:
    int mana_;
};
