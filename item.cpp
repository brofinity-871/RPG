#include "Item.h"

// CLASS: Item 
Item::Item() {
	setRarity(0);
	setEquip(false);
	setBoost(0, 0, 0, 0);
	std::cout << "Item created.[base]" << std::endl;
}
Item::Item(int r) {
	setRarity(r);
	setEquip(false);
	setBoost(0, 0, 0, 0);
	std::cout << "Item created.[Special]" << std::endl;
}
void Item::setRarity(int r) { rarity = r; }
void Item::setEquip(bool e) { equip = e; }
void Item::setBoost(int hp, int mp, int def, int dp) { stats.set_boost(hp, mp, def, dp); }
int Item::getRarity() { return rarity; }
bool Item::getEquip() { return equip; }
Boost Item::getBoost() { return stats;}
Item::~Item() {
	std::cout << "Item deleted." << std::endl;
}

// CLASS : Armor
Armor::Armor() {
	id = 1;
	setRarity(0);
	setEquip(false);
	setName("Soft Blanket");
	//setDefense(1);
	setBoost(0, 0, 10, 0);
	std::cout << "Armor created.[basic]" << std::endl;
}
Armor::Armor(std::string nm, int def) {
	id = 1;
	setRarity(0);
	setEquip(false);
	setName(nm);
	//setDefense(def);
	setBoost(0, 0, def, 0);
	std::cout << "Armor created.[Different-n,b]" << std::endl;
}
Armor::Armor(std::string nm, int def, int r, bool e) {
	id = 1;
	setRarity(r);
	setEquip(e);
	setName(nm);
	//setDefense(def);
	setBoost(0, 0, def, 0);
	std::cout << "Armor created. [Special]" << std::endl;
}
void Armor::setName(std::string nm) { armor_name = nm; }
//void Armor::setDefense(int def) { defense = def; }
std::string Armor::getName() { return armor_name; }
//int Armor::getDefense() { return defense; }
void Armor::item_info() {
	std::cout << "\t-Armor Information -\n-Name: " << getName() << "\tRarity: " << getRarity() << "\tEquip: " << getEquip() << std::endl;
	getBoost().boost_info();
}
Armor::~Armor() {
	std::cout << "Armor deleted." << std::endl;
}

// CLASS : Necklace
Necklace::Necklace() {
	id = 2;
	setRarity(0);
	setEquip(false);
	setName("Rope-Charm");
	//setHealth(1);
	setBoost(50, 0, 0, 0);
	std::cout << "Necklace created.[basic]" << std::endl;
}
Necklace::Necklace(std::string nm, int hp) {
	id = 2;
	setRarity(0);
	setEquip(false);
	setName(nm);
	//setHealth(hp);
	setBoost(hp, 0, 0, 0);
	std::cout << "Necklace created.[Different]" << std::endl;
}
Necklace::Necklace(std::string nm, int hp, int r, int e) {
	id = 2;
	setRarity(r);
	setEquip(e);
	setName(nm);
	//setHealth(hp);
	setBoost(hp, 0, 0, 0);
	std::cout << "Necklace created.[Special]" << std::endl;
}
void Necklace::setName(std::string nm) { necklace_name = nm; }
//void Necklace::setHealth(int ma) { health = ma; }
std::string Necklace::getName() { return necklace_name; }
//int Necklace::getHealth() { return health; }
void Necklace::item_info() {
	std::cout << "\t-Necklace Information-\nName: " << getName() << "\tRarity: " << getRarity() << "\tEquip: " << getEquip() << std::endl;
	getBoost().boost_info();
}
Necklace::~Necklace() {
	std::cout << "Necklace deleted." << std::endl;
}

// CLASS : Ring
Ring::Ring() {
	id = 3;
	setRarity(0);
	setEquip(false);
	setName("Wooden Band");
	//setMana(1);
	setBoost(0, 20, 0, 0);
	std::cout << "Ring created.[basic]" << std::endl;
}
Ring::Ring(std::string nm, int mp) {
	id = 3;
	setRarity(0);
	setEquip(false);
	setName(nm);
	//setMana(ma);
	setBoost(0, mp, 0, 0);
	std::cout << "Ring created.[Different]" << std::endl;
}
Ring::Ring(std::string nm, int mp, int r, bool e) {
	id = 3;
	setRarity(r);
	setEquip(e);
	setName(nm);
	//setMana(ma);
	setBoost(0, mp, 0, 0);
	std::cout << "Ring created.[Special]" << std::endl;
}
void Ring::setName(std::string ma) { ring_name = ma; }
//void Ring::setMana(int ma) { mana = ma; }
std::string Ring::getName() { return ring_name; }
//int Ring::getMana() { return mana; }
void Ring::item_info() {
	std::cout << "\t-Ring Information-\nName: " << getName() << "\tRarity: " << getRarity() << "\tEquip: " << getEquip() << std::endl;
	getBoost().boost_info();
}
Ring::~Ring() {
	std::cout << "Ring deleted." << std::endl;
}

// CLASS : Weapon
Weapon::Weapon() {
	id = 4;
	setRarity(0);
	setEquip(false);
	setName("Wooden Stick");
	//setDamage(1);
	setBoost(0, 0, 0, 5);
	std::cout << "Weapon created.[basic]" << std::endl;
}
Weapon::Weapon(std::string nm, int dp) {
	id = 4;
	setRarity(0);
	setEquip(false);
	setName(nm);
	//setDamage(dp);
	setBoost(0, 0, 0, dp);
	std::cout << "Weapon created.[Different]" << std::endl;
}
Weapon::Weapon(std::string nm, int dp, int r, bool e) {
	id = 4;
	setRarity(r);
	setEquip(e);
	setName(nm);
	//setDamage(dp);
	setBoost(0, 0, 0, dp);
	std::cout << "Weapon created.[Special]" << std::endl;
}
void Weapon::setName(std::string nm) { weapon_name = nm; }
//void Weapon::setDamage(int dp) { damage = dp; }
std::string Weapon::getName() { return weapon_name; }
//int Weapon::getDamage() { return damage; }
void Weapon::item_info() {
	std::cout << "\t-Weapon Information-\nName: " << getName() << "\tRarity: " << getRarity() << "\tEquip: " << getEquip() << std::endl;
	getBoost().boost_info();
}
Weapon::~Weapon() {
	std::cout << "Weapon deleted." << std::endl;
}




