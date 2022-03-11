//
// Created by User on 24.02.2022.
//

#include "item.h"

//diese Funktion weist einem übergebenen Gegenstand den übergebenen Namen und den übergebenen Wert zu.
// Außerdem wird das Attribut is_Valid auf true gesetzt!

void Item::initItem(const std::string& _name, int _gold){
    this->name = _name;
    this->gold = _gold;
    this->IsValid = true;
}

void Item::initItem(){
    this->IsValid = false;
}
//diese Funktion setzt das Attribut isValid des übergebenen Gegenstands auf false.


// _______________ Setter & Getter_______________________

/*void Item:: setName(const std::string& _name){
    this->name = _name;
}*/
const std::string& Item::getName() const{
    return this->name;
}


bool Item::isIsValid() const{
    return this->IsValid;
}
void Item::setIsValid(bool isValid){
    if (!isValid){
        this->IsValid = false;
    }
    else{
        this->IsValid = true;
    }

}


/*void Item::setGold (int _gold){
    this->gold = _gold;
}*/
int Item::getGold () const{
    return this->gold;
}

