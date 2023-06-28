#include <iostream>
#include "Item.cpp"
#include <vector>
#include "Character.cpp"

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

	std::cout << std::endl;

	Character me = Character("Shiva", Boost(100, 100, 100, 100));
	me.addItem(new Armor("Blanket", 1, 1, true));
	me.addItem(new Necklace("Bib", 10, 1, true));
	me.addItem(new Ring("Grass-Loop", 5, 1, true));
	me.addItem(new Weapon("Twig", 2, 1, true));
	
	me.character_info();



	return 0;
}

