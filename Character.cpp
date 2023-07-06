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
Item* Character::removeItem(){
    bool remove = false;
    if (bag.size() == 0){
        std::cout << "There are no items to remove!" << std::endl;
        return nullptr;
    }
    Item* removed = nullptr;
    do{
        std::cout << " Select from the list which item to remove.[1 ~ " << bag.size() << "]" << std::endl;
        for(int i = 0; i < bag.size(); ++i){
            std::cout << "\n[" << i + 1 << "]\tType: " << print_itemType(bag.at(i)->item_type) << std::endl;
            std::cout << "  Name: " << bag.at(i)->getName() << "\tRarity: " << print_rarity(bag.at(i)->getRarity()) << std::endl;
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
    if (removed != nullptr){
        std::cout << removed->getName() << " is removed.\n" << std::endl;
        return removed;
    }
    else{
        return nullptr;
    }
}
void Character::current_equip(){
    // Prints all items that are currently equipped. Armor, Necklace, Ring, Weapon
    std::cout << "\t-Equipped Items-" << std::endl;
    for(int i = 0; i < 4; ++i){
        if (equipped[i] == nullptr){
            std::cout << slot_equip[i] << ": empty" << std::endl; 
        }
        else{
            std::cout << slot_equip[i] << ": " << equipped[i]->getName() << std::endl;
        }
    }
    std::cout << std::endl;
}
void Character::equipItem(){
    // Menu Interface to begin equipping an item
    bool equip = false;
    do{
        std::cout << "Which item would you like to equip?" << std::endl;
        for(int i = 0; i < slot_equip.size(); ++i){
            std::cout << "  " << i + 1 << ".\t" << slot_equip[i] << std::endl;
        }
        std::cout << "To cancel 'equip an item', enter 'q'" << std::endl;

        char input;
        std::cin >> input;
        std::cin.ignore();

        if (input >= '1' && input <= char(48 + slot_equip.size())){
            std::cout << "Equipping " << slot_equip[input - 49] << std::endl;
            _equip_item_(input - 48);
            equip = true;
        }
        else if (input == 'q'){
            std::cout << "Quiting item equip" << std::endl;
            equip = true;
        }
        else{
            std::cout << "Invalid Input... " << std::endl;
        }

    } while(!equip);
}
void Character::_equip_item_(int type){
    // type is based on the choice of inputs, starting with 1 and ending with slot_equip.size()
    std::vector<Item*> list = filter_items(type);

    if (list.size() == 0){
        std::cout << "There are no " << slot_equip[type - 1] << " items to equip" << std::endl;
        return;
    }
    bool equip = false;

    do{
        std::cout << "\t" << slot_equip[type - 1] << " Items" << std::endl;
        for(int i = 0; i < list.size(); ++i){
            std::cout << i + 1 << ".\t";
            list.at(i)->item_info();
            std::cout << std::endl;
        }

        std::cout << "To cancel 'equipping " << slot_equip[type - 1] << "' enter 'q'" << std::endl;
        char input;
        std::cin >> input;

        if (input >= '1' && input <= char(list.size() + 48)){
            std::cout << list.at(input - 49)->getName() << " has been equipped." << std::endl;
            equipped[input - 49] = list.at(input - 49);
            equip = true;
        }
        else if (input == 'q'){
            std::cout << std::endl;
            equip = true;
        }
        else{
            std::cout << "Invalid Input." << std::endl;
        }
    } while (!equip);
    
}
std::vector<Item*> Character::filter_items(int t){
    // Filters the bag based on item_type. Returns all items with item_type that is equal to 't'
    std::vector<Item*> equipables;

    for(int i = 0; i < bag.size(); ++i){
        if (bag.at(i)->item_type == t && bag.at(i)->getEquip() == true){
            equipables.push_back(bag.at(i));
        }
    }
    return equipables;
}
Character::~Character(){
    std::vector<Item*>::iterator itr = bag.begin();
    for(itr; itr != bag.end(); ++itr){
        delete* itr;
    }
    bag.clear();
}

