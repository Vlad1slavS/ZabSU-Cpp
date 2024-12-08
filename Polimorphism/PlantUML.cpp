g++ -std=c++11 -I./Character -I./Warrior -I./Mage main.cpp Character/Character.cpp Warrior/Warrior.cpp Mage/Mage.cpp -o main

@startuml
class Character {
    - name : String
    - health : uint
    - attack : uint
    + Character(name: String, health: int, attack: int)
    + attack(target: Character) : void
    + printStatus() : void
    + getHealth() : int
    + setHealth(int health) : void;
}

class Warrior extends Character {
    - stamina : uint
    - defense : uint
    + Warrior(name: String, health: int, attack: int, defense: int)
    + attack(target: Character) : void
    + printStatus() : void
}

class Mage extends Character {
    - mana : uint
    + Mage(name: String, health: int, attack: int, mana: int)
    + attack(target: Character) : void
    + printStatus() : void
    + getMana() : int
}


@enduml
