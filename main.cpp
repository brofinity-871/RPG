#include <iostream>
#include "Item.cpp"
#include <vector>
#include "Menu.cpp"
#include "Character.cpp"



int main() {

	Trait testing = Trait(3, 5, 9, 10, 4, 11, 20, 8);

	testing.addTrait(7, 5, 1, 0, 6, 0, 0, 2);
	testing.trait_info();
	std::cout << std::endl;
	return 0;

	Character bob = Character("Bobby McGwyar", Boost(1000, 4900, 300, 20));
	bob.addItem(new Armor("Tank", 400, 6, true));
	bob.addItem(new Weapon("Death's Sythe", 500, 6, true));
	bob.addItem(new Weapon("Iron Sword", 30, 2, true));
	bob.addItem(new Weapon("Golden Staff", 80, 4, true));
	bob.addItem(new Weapon("Ebony Bow", 95, 4, true));
	bob.addItem(new Weapon("Plastic Sword", 1, 1, true));

	bob.character_info();
	//bob.printBag();
	bob.equipItem();
	bob.equipItem();

	bob.current_equip();

	bob.character_info();

	return 0;
	
	Boost b = Boost(100, 250, 45, 20);
	b.boost_info();
	std::cout << std::endl;

	Item* def = new Armor("Demonic Shield", 169, -1, true);
	Item* charm = new Necklace("Ghostly Choker", 400, -1, true);
	Item* band = new Ring("Mini-Death", 600, -1, true);
	Item* wep = new Weapon("Holy Sword", 500, -1, true);

	def->item_info();
	std::cout << std::endl;
	charm->item_info();
	std::cout << std::endl;
	band->item_info();
	std::cout << std::endl;
	wep->item_info();
	std::cout << std::endl;

	std::cout << "Hello World" << std::endl;

	delete def;
	delete charm;
	delete band;
	delete wep;

	std::cout << std::endl;

	Character me = Character("Shiva", Boost(100, 100, 100, 100));
	me.addItem(new Armor("Blanket", 1, 1, true));
	me.addItem(new Necklace("Bib", 10, 1, true));
	me.addItem(new Ring("Grass-Loop", 5, 1, true));
	me.addItem(new Weapon("Twig", 2, 1, true));

	me.character_info();
	me.removeItem();
	me.printBag();

	me.current_equip();
	me.equipItem();
	//Menu* game = new Start();
	//game->display_menu();

	//delete game;

	return 0;
}

/*
'0' = 48
'9' = 57
'A' = 65
'Z' = 90
'a' = 97
'z' = 122

*/

