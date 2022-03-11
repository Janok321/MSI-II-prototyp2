//
// Created by User on 24.02.2022.
//

#ifndef MSE_EXSH2_ITEM_H
#define MSE_EXSH2_ITEM_H


#include <string>

class Item {

private:
    std:: string name;
    int gold;
    bool IsValid;

public:
void initItem(const std::string& _name, int _gold);

void initItem();

//_________________Getter & Setter________________

//void setName(const std::string& _name);
const std::string& getName() const;


//void setGold (int _gold);
int getGold () const;

bool isIsValid() const;
void setIsValid(bool IsValid);

};

#endif //MSE_EXSH2_ITEM_H
