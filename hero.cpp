//
// Created by User on 24.02.2022.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "hero.h"


//_____________Getter & Setter ______________________

const std::string &Hero::getName() const {
    return this->name;
}

void Hero::setHealth(int _health){
    if (_health >= 0){
        Hero::health = _health;
    }
    else{
        std::cout << "Ungültige Lebenspunkte " << std::endl;
    }
    //alternativ
    // this->health = _health;
}

int Hero::getHealth() const{
    return this->health;
}

void Hero::setGold (int _gold) {
    if (gold >= 0){
        this->gold = _gold;
    }
    else{
        std::cout << "Gold kann nicht negativ sein" << std::endl;
    }
}

int Hero::getGold() const{
    return this->gold;
}

Item *Hero::getInventory(int index){
    Item &item = this->inventory[index];
    return &item;
}
//___________________________________________________________

int Hero::addInventarItem(const Item& item){
    for (int i = 0; i < 10; i++) {
        if(!inventory[i].isIsValid()){
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

int Hero::addEquipmentItem(const Item& item){
    for (int i = 0; i < 2; i++) {
        if(!gear[i].isIsValid()){
            gear[i] = item;
            return i;
        }
    }
    return -1;
}

Item* Hero::removeInventarItem(int slot) {
    if (this->inventory[slot].isIsValid() && slot >= 0 && slot < 10) {
        this->inventory[slot].setIsValid(false); //alternativ initItem()
        return &this->inventory[slot];
    } else {
        return nullptr;             // Aufgabenstellung/Forum checken
    }
}

Item* Hero::removeEquipmentItem(int slot){
    if(this-> gear[slot].isIsValid() && slot >= 0 && slot < 2){
        this->gear[slot].setIsValid(false); //alternativ initItem()
        return &this->gear[slot];
    }
    else{
        return nullptr;             // Aufgabenstellung/Forum checken
    }

}
//(Klassen Hero und Character): Der übergebene Gegenstand wird zum Inventar der Heldin bzw. des Charakters hinzugefügt.
// Der Rückgabewert entspricht dem Slot Platz (= Stelle im Array), an dem der Gegenstand eingereiht wurde. Sind alle
// Plätze belegt, soll der Wert -1 zurückgegeben werden.

void Hero::initHero(const std::string& _name, int _health, int _gold) {
    this ->name = _name;
    this ->health = _health;
    this ->gold = _gold;
    for (int i = 0; i < 10; i++) {
        this->inventory[i].initItem();
    }
    for (int i = 0; i < 2; i++){
        this->gear[i].initItem();
    }
}

//Die Heldin greift einen spezifizierten Gegner an und reduziert dessen Lebenspunkte zufällig um einen Wert
// zwischen 15 und 25
void Hero::attack(Character& enemy){
    int damage = 15 + std::rand() % 11;
    std::cout << this->name << " trifft " <<enemy.getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - damage);
}


//Verkauft einen Gegenstand an der spezifizierten Stelle im Inventar
// (überprüfen Sie, ob an dieser Stelle ein Gegenstand existiert! Hinweis: isValid) um dessen Wert.
// Dieser Betrag wird zum Gold der Heldin addiert.

void Hero::sellItem(int index){
    if (index >= 0 && index < 10) {
        if (inventory[index].isIsValid()) {                             //alternativ:
            setGold(getGold()+inventory[index].getGold());        //this->gold+= this->inventory[index].getGold();
            inventory[index].initItem();                                // Setzt IsValid des Items auf false
            std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. ";
            std::cout << name << " besitzt nun " << gold << " Gold." << std::endl;
        }
    }
}


//Simuliert einen Kampf zwischen der Heldin und einem Feind, der aus mehreren Runden besteht.
// In jeder Runde wird zuerst die attack()-Funktion der Heldin und dann die entsprechende Funktion
// des Feindes aufgerufen, solange bis die Heldin oder der Feind keine Lebenspunkte mehr übrig hat.
// Der Rückgabewert ist true, wenn die Heldin gewinnt, ansonsten false.

bool Hero::fight(Character &enemy){
    while (this->getHealth() > 0 && enemy.getHealth() > 0) {
        this->attack(enemy);
        if (enemy.getHealth() > 0) {
            enemy.attack(this);
        }
    }
    return this->health > 0;
}

