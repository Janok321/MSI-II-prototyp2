//
// Created by User on 24.02.2022.
//

#ifndef MSE_EXSH2_HERO_H
#define MSE_EXSH2_HERO_H


#include <string>
#include "item.h"
#include "character.h"

class Character;

class Hero {
private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];
    Item gear[2];

public:
    void initHero(const std::string& name, int _health, int _gold);

    void attack(Character& enemy);

    void sellItem(int index);

    bool fight(Character& enemy);

    int addInventarItem(const Item& item);
    int addEquipmentItem(const Item& item);

    Item* removeInventarItem(int slot);
    Item* removeEquipmentItem(int slot);



    //____Getter & Setter____

    const std::string& getName() const;

    int getHealth () const;
    void setHealth(int _health);

    int getGold() const;
    void setGold (int _gold);

    Item *getInventory(int index);

};


#endif //MSE_EXSH2_HERO_H
