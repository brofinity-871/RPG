#include "Spell.h"


// CLASS: Spell
Spell::Spell(){
    std::cout << "Spell created." << std::endl;
    setName("Focus");
    setElemType(0);
}
Spell::Spell(std::string nm, int et){
    std::cout << "Spell created." << std::endl;
    setName(nm);
    setElemType(et);
}
void Spell::setName(std::string nm) { spell_name = nm; }
void Spell::setElemType(int e) { element_type = e; }
std::string Spell::getName() { return spell_name; }
int Spell::getElemType() { return element_type; }
Spell::~Spell(){
    std::cout << "Spell deleted." << std::endl;
}


// CLASS: 
Dud::Dud(){
    std::cout << "Dud spell created." << std::endl;
    setName("A blank spell");
    setElemType(0);
}
void Dud::spell_info(){
    std::cout << "\t- Dud Information -" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Element: " << print_elem_type(getElemType()) << "\n"<< std::endl;
}
Dud::~Dud(){
    std::cout << "Dud spell deleted." << std::endl;
}

