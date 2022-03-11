//
// Created by User on 24.02.2022.
//

#include <iostream>
#include "character.h"

int Character::addInventarItem(const Item& item){               //Funktion fügt Gegenstand hinzu, wenn an der Indexstelle noch keiner vorhanden
    for (int i = 0; i < 10; i++) {
        if(!inventory[i].isIsValid()){
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item* Character::removeInventarItem(int slot){
    if(this-> inventory[slot].isIsValid() && slot >= 0 && slot < 10){
        this->inventory[slot].setIsValid(false);
        return &this->inventory[slot];
    }
    else{
        return nullptr;             // Aufgabenstellung/Forum checken
    }
}

const std::string& Character::getName() const {
    return this->name;
}

void Character::setHealth(int _health){
    this->health = _health;
}

int Character::getHealth() const{
    return this->health;
}

Item* Character::getInventory(int index){
    Item &item = this->inventory[index];
    return &item;
}

void Character::initCharacter(const std::string& _name, int _health, int _gold){
    this->name = _name;
    this->health = _health;
    this->gold = _gold;
    for (int i = 0; i < 10; i++) {
       this->inventory[i].initItem();
    }
}

void Character::attack(Hero* hero){
    int damage = 5 + std::rand() % 11;
    std::cout << this->name << " trifft " <<hero->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    hero->setHealth((hero->getHealth() - damage));
}
//Der Charakter greift die spezifizierte Heldin an und reduziert deren Lebenspunkte zufällig um einen Wert zwischen 5 und 15.
