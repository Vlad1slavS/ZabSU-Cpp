#include <iostream>
#include <string>

class Warrior : public Character {
public:
    Warrior(std::string name, int health, int attack, int defense, int stamina)
        : Character(name, health, attack), defense_(defense), stamina_(stamina) {}

    void attack(Character& target) const override {
        int damage = attack_ + 5; // Бонус к урону
        target.takeDamage(damage);
        std::cout << name_ << " (Воин) атаковал " << target.getName() 
                  << ", нанеся " << damage << " урона!" << std::endl;
        std::cout << target.getName() << " осталось " << target.getHealth() 
                  << " здоровья." << std::endl;
    }

    void printStatus() const override {
        std::cout << "Имя: " << name_ 
                  << ", Здоровье: " << health_ 
                  << ", Атака: " << attack_ 
                  << ", Защита: " << defense_ 
                  << ", Выносливость: " << stamina_ << std::endl;
    }

private:
    int defense_;
    int stamina_;
};