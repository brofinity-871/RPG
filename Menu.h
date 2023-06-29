#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

class Menu{
private:
    bool quit = false;
public:
    // Constructors
    Menu();

    // Accessors
    void setQuit(bool);
    bool getQuit();

    // Functions
    virtual void display_menu() = 0;
    virtual ~Menu();
};

class Start : public Menu{
private:
    std::vector<std::string> options = {"Start", "Settings", "Quit"};
public:
    // Constructor(s)
    Start();

    // Accessors

    // Start Functions
    void display_menu();
    ~Start();
    
};


#endif // MENU_H