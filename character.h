//
// Created by User on 24.02.2022.
//

#ifndef MSE_EXSH2_CHARACTER_H
#define MSE_EXSH2_CHARACTER_H

#include <string>
#include "item.h"
#include "hero.h"

class Hero;

class Character {

private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

public:
    void initCharacter(const std::string& _name, int _health, int _gold);

    void attack(Hero* hero);

    int addInventarItem(const Item& item);

    Item* removeInventarItem(int slot);


// Getter & Setter

    const std::string& getName() const;

    void setHealth(int _health);
    int getHealth() const;

    Item *getInventory(int index);

};

#endif //MSE_EXSH2_CHARACTER_H
