
#ifndef ITEM_H
#define ITEM_H

/*	WELCOME TO ITEM CLASS
*	ALL ITEMS WILL HAVE 'BOOST' characteristics.

This file includes:
*	- Armor 	(Item: Character)
*	- Necklace  (Item: Character)
*	- Ring  	(Item: Character)
*	- Weapon  	(Item: Character)
* 	- 
* Plan to include other kinds of items. The 4 above are for equipping onto a character (single)
* Future items will have additional charactersitcs.

traits: {strength [PHYSICAL] = Body, Might, Brawn, Power; 
		constituion [PHYSICAL] = Stamina, Endurance, Vitality, Recovery;
		defense [PHYSICAL] = Resistance, Resilience;
		dexterity [PHYSICAL] = Agility, Reflexes, Quickness;
		charisma [MENTAL]= Presence, Charm, Social;
		perception [MENTAL] = Alertness, Awareness, Cautiousness;
		wisdom [MENTAL] = Spirit, Wits, Psyche, Sense;
		luck [MENTAL] = Fate, Chance;
		}

*/	

#include <iostream>
#include <string>

std::string print_rarity(int r){
	if (r == 0){
		return "None";
	}
	else if (r == 1){
		return "Common";
	}
	else if (r == 2){
		return "Uncommon";
	}
	else if (r == 3){
		return "Rare";
	}
	else if (r == 4){
		return "Ultra-Rare";
	}
	else if (r == 5){
		return "Legendary";
	}
	else if (r == 6){
		return "Mythic";
	}
	else if (r == 7){
		return "One-of-a-Kind";
	}
	else{
		return "Mystery";
	}
}
std::string print_equip(bool e){
	if (e){
		return "Can Equip";
	}
	else
		return "Can NOT Equip";
}
std::string print_itemType(int t){
	if (t == 1){
		return "Armor";
	}
	else if (t == 2){
		return "Necklace";
	}
	else if (t == 3){
		return "Ring";
	}
	else if (t == 4){
		return "Weapon";
	}
	else{
		return "Unknown";
	}
}

struct Trait{
	int strength, constitution, defense, dexterity, charisma, perception, wisdom, luck;
	Trait(){
		strength = 0;
		constitution = 0;
		defense = 0;
		dexterity = 0;
		charisma = 0;
		perception = 0;
		wisdom = 0;
		luck = 0;
	}
	Trait(int str, int cnstut, int defen, int dxtrt, int chrsm, int prcpt, int wsdm, int lk){
		strength = str;
		constitution = cnstut;
		defense = defen;
		dexterity = dxtrt;
		charisma = chrsm;
		perception = prcpt;
		wisdom = wsdm;
		luck = lk;
	}
	void addTrait(int str, int cnstut, int defen, int dxtrt, int chrsm, int prcpt, int wsdm, int lk){
		strength += str;
		constitution += cnstut;
		defense += defen;
		dexterity += dxtrt;
		charisma += chrsm;
		perception += prcpt;
		wisdom += wsdm;
		luck += lk;
	}
	void addTrait(Trait tr){
		strength += tr.strength;
		constitution += tr.constitution;
		defense += tr.defense;
		dexterity += tr.dexterity;
		charisma += tr.charisma;
		perception += tr.perception;
		wisdom += tr.wisdom;
		luck += tr.luck;
	}
	void subtractTrait(int str, int cnstut, int defen, int dxtrt, int chrsm, int prcpt, int wsdm, int lk){
		strength -= str;
		constitution -= cnstut;
		defense -= defen;
		dexterity -= dxtrt;
		charisma -= chrsm;
		perception -= prcpt;
		wisdom -= wsdm;
		luck -= lk;
	}
	void subtractTrait(Trait tr){
		strength -= tr.strength;
		constitution -= tr.constitution;
		defense -= tr.defense;
		dexterity -= tr.dexterity;
		charisma -= tr.charisma;
		perception -= tr.perception;
		wisdom -= tr.wisdom;
		luck -= tr.luck;
	}
	void trait_info(){
		std::cout << "\t-Trait Information-" << std::endl;
		std::cout << "Strength: " << strength << "\tConstitution: " << constitution << std::endl;
		std::cout << "Defense: " << defense << "\tCharisma: " << charisma << std::endl;
		std::cout << "Perception: " << perception << "\tWisdom: " << wisdom << std::endl;
		std::cout << "Luck: " << luck << std::endl;
	}
};

struct Boost{
	// Variables
	int health, mana, defense, damage;
	
	// Constructor(s)
	Boost(){
		health = 100;
		mana = 50;
		defense = 10;
		damage = 5;
	}
	Boost(int hp, int mp, int def, int dp){
		health = hp;
		mana = mp;
		defense = def;
		damage = dp;
	}

	// Boost Function
	void set_boost(int hp, int mp, int def, int dp){
		health = hp;
		mana = mp;
		defense = def;
		damage = dp;
	}
	void boost_info(){
		std::cout << "Health: " << health << "\tMana: " << mana << std::endl;
		std::cout << "Defense: " << defense << "\tDamage: " << damage << std::endl;
	}
	void addBoost(int hp, int mp, int def, int dp){
		health += hp;
		mana += mp;
		defense += def;
		damage += dp;
	}
	void addBoost(Boost stats){
		health += stats.health;
		mana += stats.mana;
		defense += stats.defense;
		damage += stats.damage;
	}
	void subtractBoost(int hp, int mp, int def, int dp){
		health -= hp;
		mana -= mp;
		defense -= def;
		damage -= dp;
	}
	void subtractBoost(Boost stats){
		health -= stats.health;
		mana -= stats.mana;
		defense -= stats.defense;
		damage -= stats.damage;
	}
};

class Item {
private:
	std::string item_name;
	int rarity;
	bool equip;
	Boost stats;
	// price
	// traits

public:
	// Variable 
	int item_type = 0;
	// Constructor
	Item();
	Item(int rarity);

	// Accessors
	void setRarity(int r);
	void setEquip(bool e);
	void setBoost(int hp, int mp, int def, int dp);
	void setName(std::string n);
	int getRarity();
	bool getEquip();
	Boost getBoost();
	std::string getName();

	// Item Functions
	void basic_itemInfo();

	// Virtual Functions
	virtual void item_info() = 0;
	virtual ~Item();
};

class Armor : public Item {
private:
	//std::string armor_name;
	//int defense;
public:
	// Constructor(s)
	Armor();
	Armor(std::string nm, int def);
	Armor(std::string nm, int def, int r, bool e);
	
	// Accessors
	//void setName(std::string nm);
	//void setDefense(int def);
	//std::string getName();
	//int getDefense();

	// Armor Functions
	void item_info();
	~Armor();
};

class Necklace : public Item {
private:
	//std::string necklace_name;
	//int health;
public:
	// Constructor(s)
	Necklace();
	Necklace(std::string nm, int hp);
	Necklace(std::string nm, int hp, int r, int e);

	// Accessors
	//void setName(std::string nm);
	//void setHealth(int ma);
	//std::string getName();
	//int getHealth();

	// Necklace Functions
	void item_info();
	~Necklace();
};

class Ring : public Item {
private:
	//std::string ring_name;
	//int mana;
public:
	// Constructor(s)
	Ring();
	Ring(std::string nm, int mp);
	Ring(std::string nm, int mp, int r, bool e);

	// Accessors
	//void setName(std::string nm);
	//void setMana(int ma);
	//std::string getName();
	//int getMana();

	// Ring Function
	void item_info();
	~Ring();
};

class Weapon : public Item {
private:
	//std::string weapon_name;
	//int damage;
public:
	// Constructors
	Weapon();
	Weapon(std::string nm, int dp);
	Weapon(std::string nm, int dp, int r, bool e);

	// Accessors
	//void setName(std::string nm);
	//void setDamage(int dp);
	//std::string getName();
	//int getDamage();

	// Weapon Function
	void item_info();
	~Weapon();
};


#endif //ITEM_H