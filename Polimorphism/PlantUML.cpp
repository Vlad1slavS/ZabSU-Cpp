g++ -std=c++11 -I./Character -I./Warrior -I./Mage main.cpp Character/Character.cpp Warrior/Warrior.cpp Mage/Mage.cpp -o main

@startuml
class Character {
    - name : String
    - health : uint
    - attack : uint
    + Character(name: String, health: uint, attack: uint)
    + attack(target: Character) : void
    + printStatus() : void
    + getHealth() : uint
    + setHealth(uint health) : void;
    + setAttack(uint attack) : void;
}

class Warrior extends Character {
    - stamina : uint
    - defense : uint
    + Warrior(name: String, health: uint, attack: uint, defense: uint)
    + attack(target: Character) : void
    + printStatus() : void
    + setDefense(uint defense) : void;
}

class Mage extends Character {
    - mana : uint
    + Mage(name: String, health: uint, attack: uint, mana: uint)
    + attack(target: Character) : void
    + printStatus() : void
    + getMana() : uint
    + setMana(uint mana) : void;
}


@enduml
