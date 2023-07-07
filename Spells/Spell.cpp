#include "Spell.h"


// CLASS: Spell
Spell::Spell(){
    std::cout << "Spell created." << std::endl;
    setName("Focus");
    setSpellType(0);
    setElemType(0);
}
Spell::Spell(std::string nm, int st, int et){
    std::cout << "Spell created." << std::endl;
    setName(nm);
    setSpellType(st);
    setElemType(et);
}
void Spell::setName(std::string nm) { spell_name = nm; }
void Spell::setSpellType(int t) { spell_type = t; }
void Spell::setElemType(int e) { element_type = e; }
std::string Spell::getName() { return spell_name; }
int Spell::getSpellType() { return spell_type; }
int Spell::getElemType() { return element_type; }
Spell::~Spell(){
    std::cout << "Spell deleted." << std::endl;
}


// CLASS: 
Dud::Dud(){
    std::cout << "Dud spell created." << std::endl;
    setName("A blank spell");
    setSpellType(0);
    setElemType(0);
}
void Dud::spell_info(){
    std::cout << "\t- Dud Information -" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << print_spell_type(getSpellType()) << std::endl;
    std::cout << "Element: " << print_elem_type(getElemType()) << "\n"<< std::endl;
}
Dud::~Dud(){
    std::cout << "Dud spell deleted." << std::endl;
}

