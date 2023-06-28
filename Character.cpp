#include "Character.h"

Character::Character(){
    bag.resize(capacity, nullptr);
    traits = Boost();
}
void Character::setName(std::string nm) { character_name = nm; }
void Character::setBag(){
    for(int i = 0; i < capacity; ++i) { bag.push_back(nullptr);}
}
std::string Character::getName() { return character_name; }
std::vector<Item*> Character::getBag() { return bag; }
Boost Character::getTraits() { return traits; }
/*
Boost Character::total_stats(){
    std::vector<Item*>::iterator itr = bag.begin();
    Boost added_stats = Boost(0, 0, 0, 0);

    for(itr; itr != bag.end(); ++itr){
        if((*itr) != nullptr)
        added_stats.addBoost((*itr)->getBoost());
    }
    added_stats.addBoost(traits);

    return added_stats;
}
*/
Character::~Character(){
    std::vector<Item*>::iterator itr = bag.begin();
    for(itr; itr != bag.end(); ++itr){
        delete* itr;
    }
    bag.clear();
}

