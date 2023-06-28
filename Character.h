
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
public:
    // Constructor(s)
    Character();

    // Accessors
    void setName(std::string nm);
    void setBag();
//void setTraits();
    std::string getName();
    std::vector<Item*> getBag();
    Boost getTraits();

    // Character Functions
    //Boost total_stats();
    

    ~Character();
};

#endif //CHARACTER_H