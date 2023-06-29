
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"
#include <vector>

std::vector<std::string> equipped = {"Armor", "Necklace", "Ring", "Weapon"};

class Character{
private:
    std::string character_name;
    int capacity = 10;
    std::vector<Item*> bag;
    Boost traits;
    // need equippable items different from bag
    // Item* equipped[4] = nullptr;   // [0] = armor, [1] = necklace, [2] = ring, [3] = weapon
public:
    // Constructor(s)
    Character();
    Character(std::string nm, Boost sts);

    // Accessors
    void setName(std::string nm);
//void setTraits();
    std::string getName();
    std::vector<Item*> getBag();
    Boost getTraits();

    // Character Functions
    //Boost total_stats();
    void character_info();
    void printBag();
    void addItem(Item* itm);
    Item* removeItem();

    ~Character();
};

#endif //CHARACTER_H