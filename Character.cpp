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
/*
Item* Character::removeItem(){
    // There should be options to not want to remove an item, and to select which item to remove.
    // Should not be possible to be stuck within loop!
    // go-to visual studio 2022 to check this section/algorithm of removing an item(PROPERLY)
    bool remove = false;
    if (bag.size() == 0){
        std::cout << "There are no items to remove!" << std::endl;
        return nullptr;
    }
    Item* removed = nullptr;
    do{
        std::cout << " Select from the list which item to remove.[1 ~ " << bag.size() << "]" << std::endl;
        for(int i = 0; i < bag.size(); ++i){
            std::cout << "\n[" << i + 1 << "]  ";
            bag.at(i)->item_info();
        }
        std::cout << "To cancel 'removing an item', enter 'q'." << std::endl;

        char input;
        std::cout << "\nInput: ";

        std::cin >> input;
        std::cin.ignore();

        if (input <= char(48 + bag.size()) && input >= '1'){
            //return bag.at(input - 1);
            std::vector<Item*>::iterator itr = bag.begin();
            itr += int(input) - 49;     // 49 = 1 + 48: 1 is for the shift of 0 to 1; 48 is the shift from char to int.
            removed = *itr;
            bag.erase(itr);
            bag.shrink_to_fit();
            remove = true;
        }
        else if (input == 'q'){
            std::cout << "No longer removing item" << std::endl;
            remove = true;
        }
        else {
            std::cout << "Invalid Input. Please try again." << std::endl;
        }
        std::cout << std::endl;
    } while (!remove);
    return removed;
}
*/
Character::~Character(){
    std::vector<Item*>::iterator itr = bag.begin();
    for(itr; itr != bag.end(); ++itr){
        delete* itr;
    }
    bag.clear();
}

