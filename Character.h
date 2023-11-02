
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Item.h"
#include <vector>

std::vector<std::string> slot_equip = {"Armor", "Necklace", "Ring", "Weapon"};

class character_equip{
private:
    std::vector<Item*> equipped;
public: 
    // Constructor
    character_equip();

    // Accesors
    

    // Functions

};

class Character{
private:
    std::string character_name;
    int capacity = 10;
    std::vector<Item*> bag;
    Boost char_boost;
    // need equippable items different from bag
    Item* equipped[4] = {nullptr, nullptr, nullptr, nullptr};   // [0] = armor, [1] = necklace, [2] = ring, [3] = weapon
    
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
    Boost total_stats();
    void character_info();
    void printBag();
    void addItem(Item* itm);
    Item* removeItem();
    void equipItem();
    void current_equip();
    std::vector<Item*> filter_items(int t);
    void _equip_item_(int type);

    ~Character();
};

#endif //CHARACTER_H