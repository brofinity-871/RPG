#include "Character.h"

Character::Character(){
    traits = Boost();
    setName("Jone Doe");
}
Character::Character(std::string nm, Boost sts){
    setName(nm);
    traits = sts;
}
void Character::setName(std::string nm) { character_name = nm; }
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
void Character::character_info(){
    std::cout << "\t-" << getName() << " Information-" << std::endl;
    getTraits().boost_info();
    printBag();
}
void Character::printBag(){
    int count = 0;
    for(int i = 0; i < bag.size(); ++i){
        if (bag[i] != nullptr){
            std::cout << "[Bag:" << count + 1 << "]";
            bag.at(i)->item_info();
            std::cout << std::endl;
            count++;
        }
    }
    if (count == 0){
        std::cout << "Bag empty." << std::endl;
    }

}
void Character::addItem(Item* itm){
    if (bag.size() >= capacity){
        std::cout << "Cannot add item. Bag at max capacity." << std::endl;
    }
    else{
        bag.push_back(itm);
    }
}
Character::~Character(){
    std::vector<Item*>::iterator itr = bag.begin();
    for(itr; itr != bag.end(); ++itr){
        delete* itr;
    }
    bag.clear();
}

