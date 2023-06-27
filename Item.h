#pragma once

/*	WELCOME TO ITEM CLASS
* This file includes:
*	- Armor
*	- Necklace
*	- Ring
*	- Weapon
* 
* 
* 
* Plan to include other kinds of items. The 4 above are for equipping onto a character (single)
* Future items will have additional charactersitcs.


*/	

#include <iostream>
#include <string>

class Item {
private:
	int rarity;
	bool equip;
public:
	// Constructor
	Item();
	Item(int rarity);

	// Accessors
	void setRarity(int r);
	void setEquip(bool e);
	int getRarity();
	bool getEquip();

	// Virtual Functions
	virtual void item_info() = 0;
	virtual ~Item();
};

class Armor : public Item {
private:
	std::string armor_name;
	int defense;
public:
	// Constructor(s)
	Armor();
	Armor(std::string nm, int def);
	Armor(std::string nm, int def, int r, bool e);
	
	// Accessors
	void setName(std::string nm);
	void setDefense(int def);
	std::string getName();
	int getDefense();

	// Armor Functions
	void item_info();
	~Armor();
};

class Necklace : public Item {
private:
	std::string necklace_name;
	int health;
public:
	// Constructor(s)
	Necklace();
	Necklace(std::string nm, int ma);
	Necklace(std::string nm, int ma, int r, int e);

	// Accessors
	void setName(std::string nm);
	void setHealth(int ma);
	std::string getName();
	int getHealth();

	// Necklace Functions
	void item_info();
	~Necklace();
};

class Ring : public Item {
private:
	std::string ring_name;
	int mana;
public:
	// Constructor(s)
	Ring();
	Ring(std::string nm, int ma);
	Ring(std::string nm, int ma, int r, bool e);

	// Accessors
	void setName(std::string nm);
	void setMana(int ma);
	std::string getName();
	int getMana();

	// Ring Function
	void item_info();
	~Ring();
};
class Weapon : public Item {
private:
	std::string weapon_name;
	int damage;
public:
	// Constructors
	Weapon();
	Weapon(std::string nm, int dp);
	Weapon(std::string nm, int dp, int r, bool e);

	// Accessors
	void setName(std::string nm);
	void setDamage(int dp);
	std::string getName();
	int getDamage();

	// Weapon Function
	void item_info();
	~Weapon();
};
