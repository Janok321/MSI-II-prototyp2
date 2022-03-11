#include <iostream>
#include "hero.h"
#include <ctime>


int main() {

    std::srand(time(0));

    Item item;

    Hero annina;
    annina.initHero("Annina", 300, 50);
    item.initItem("Lichtschwert", 200);
    annina.addEquipmentItem(item);

    Character matthias;
    matthias.initCharacter((std::string)"Matthias", 50, 50);
    item.initItem("Zaubertrank", 50);
    matthias.addInventarItem(item);
    item.initItem("magisches Zepter", 150);
    matthias.addInventarItem(item);

    Character pascal;
    pascal.initCharacter("Pascal", 100, 100);
    item.initItem("Hellseher-Trunk", 100);
    pascal.addInventarItem(item);
    item.initItem("klappriges Schwert", 50);
    pascal.addInventarItem(item);

    int inventar_counter = 2;
    int randomValue;

    if (annina.fight(matthias)) {
        std::cout << matthias.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealth()<< " Lebenspunkte uebrig!" << std::endl;

        randomValue = std::rand() % (inventar_counter + 1);
        if(!annina.addInventarItem(*matthias.removeInventarItem(randomValue))) {
            std::cout << "Kein Platz mehr vorhanden!" << std::endl;
        }
        else {
            annina.addInventarItem(*pascal.removeInventarItem(randomValue));
            std::cout << "Gegenstand " << pascal.getInventory(randomValue)->getName()
                      << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
        }
    }
    else {
        std::cout << annina.getName() << " fiel in Ohnmacht!" << std::endl;
        return 0;
    }


    if (annina.fight(pascal)) {
        std::cout << pascal.getName() << " fiel in Ohnmacht! " << annina.getName() << " hat noch " << annina.getHealth() << " Lebenspunkte uebrig!" << std::endl;

        randomValue = std::rand() % (inventar_counter + 1);
        if(!annina.addInventarItem(*pascal.removeInventarItem(randomValue))){
            std::cout << "Kein Platz mehr vorhanden!" << std::endl;
        }
        else{
            annina.addInventarItem(*pascal.removeInventarItem(randomValue));
            std::cout <<"Gegenstand " << pascal.getInventory(randomValue)->getName() << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
        }
    }
    else {
        std::cout << annina.getName() << " fiel in Ohnmacht!" << std::endl;
        return 0;
    }

    for (int i = 0; i < 10; i++)
        annina.sellItem(i);

    return 0;
}

//Schreiben Sie nun ein kleines Testprogramm, bei welchem eine Heldin mit 300 Lebenspunkten erst gegen
// einen Charakter mit 50 Lebenspunkten und danach gegen einen Charakter mit 100 Lebenspunkten kämpft.
//Nach jedem gewonnenen Kampf fügen Sie einen beliebigen Gegenstand als Beute ins Inventar der Heldin ein.
// Ganz am Ende verkauft die Heldin die gewonnenen Gegenstände, falls sie noch am Leben ist.