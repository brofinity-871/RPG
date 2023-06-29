#include "Menu.h"

Menu::Menu(){
    setQuit(false);
    std::cout << "Menu created" << std::endl;
}
void Menu::setQuit(bool q) { quit = q; }
bool Menu::getQuit() { return quit; }
Menu::~Menu(){
    std::cout << "Menu Deleted." << std::endl;
}
/*
void Menu::display_menu(){
    do{
        std::cout << "Welcome to menu!" << std::endl;
        std::vector<std::string> options = {"Start", "Settings", "Quit"};

        for(int i = 0; i < options.size(); i++){
            std::cout << "[" << i + 1 << "]  " << options.at(i) << std::endl;
        }

        char input;
        std::cout << "Input: ";
        std::cin >> input;
        std::cin.ignore();

        if (input == '1'){
            std::cout << "Starting game..." << std::endl;
            setQuit(true);
        }
        else if (input == '2'){
            std::cout << "Opening Settings..." << std::endl;
        }
        else if (input == '3'){
            std::cout << "Goodbye." << std::endl;
            setQuit(true);
        }
        else{
            std::cout << "Invalid input. Please try again." << std::endl;
        }

    } while(!getQuit());
}
*/

// CLASS: Start
Start::Start(){
    setQuit(false);
    std::cout << "Start menu created." << std::endl;
}
void Start::display_menu(){

    do{
        std::cout << "Welcome! Select from the following." << std::endl;
        for(int i = 0; i < options.size(); ++i){
            std::cout << i+1 << ".  " << options.at(i) << std::endl;
        }
        char input;
        std::cout << "Input: ";
        std::cin >> input;
        std::cin.ignore();
        
        if (input == '1'){
            std::cout << "Starting game..." << std::endl;
            setQuit(true);
        }
        else if (input == '2'){
            std::cout << "Opening settings" << std::endl;
        }
        else if (input == '3'){
            std::cout << "Quiting game. Goodbye." << std::endl;
            setQuit(true);
        }
        else{
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        
        std::cout << std::endl;
    } while (!getQuit());
}
Start::~Start(){
    std::cout << "Start menu deleted." << std::endl;
}

