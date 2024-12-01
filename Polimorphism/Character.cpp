#include <string>
#include <iostream>

class Character {
public:
    Character(std::string name, int health, int attack) 
        : name_(name), health_(health), attack_(attack) {}
    virtual ~Character() = default; // Виртуальный деструктор

    virtual void attack(Character& target) const {
        int damage = attack_;
        target.takeDamage(damage); // Используем публичный метод для изменения здоровья
        std::cout << name_ << " атаковал " << target.getName() 
                  << ", нанеся " << damage << " урона!" << std::endl;
        std::cout << target.getName() << " осталось " << target.getHealth() 
                  << " здоровья." << std::endl;
    }

    virtual void printStatus() const {
        std::cout << "Имя: " << name_ 
                  << ", Здоровье: " << health_ 
                  << ", Атака: " << attack_ << std::endl;
    }

    int getHealth() const { return health_; }
    std::string getName() const { return name_; }

    void takeDamage(int damage) {
        health_ -= damage;
        if (health_ < 0) health_ = 0; // Не допускаем отрицательное здоровье
    }

protected:
    std::string name_;
    int health_;
    int attack_;
};
