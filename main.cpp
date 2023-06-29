#include <iostream>
#include "Item.cpp"
#include <vector>
#include "Menu.cpp"

int main() {
	
	
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

	Menu* game = new Start();

	game->display_menu();

	delete game;

	return 0;
}

