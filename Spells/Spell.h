#ifndef SPELL_H
#define SPELL_H

/*
    SPELL INFORMATION
TYPES:
    - 0 = Neutral
    - 1 = Attack
    - 2 = Heal
    - 3 = Boost
    - 4 = Curse
    - 5 = Status

ELEMENTS:
    - 0 = Null
    - 1 = Fire
    - 2 = Earth
    - 3 = Water
    - 4 = Air
    - 5 = Light
    - 6 = Dark

*/

#include <iostream>

std::string print_elem_type(int type){
    if (type == 1){
        return "Fire";
    }
    else if (type == 2){
        return "Earth";
    }
    else if (type == 3){
        return "Water";
    }
    else if (type == 4){
        return "Air";
    }
    else if (type == 5){
        return "Light";
    }
    else if (type == 6){
        return "Dark";
    }
    else if (type == 0){
        return "Null";
    }
    else
        return "Unknown";
}
struct Trait{
    int cost, damage, heal;
    Boost boost, curse;
};

class Spell{
private:
    std::string spell_name;
    int element_type;
public:
    // Constructors
    Spell();
    Spell(std::string nm, int et);

    // Accessors
    void setName(std::string nm);
    void setElemType(int e);
    std::string getName();
    int getElemType();

    // Spell Functions
    virtual void spell_info() = 0;
    virtual ~Spell();
};

class Dud : public Spell{
public:
    Dud();

    void spell_info();
    ~Dud();
};

#endif // SPELL_H