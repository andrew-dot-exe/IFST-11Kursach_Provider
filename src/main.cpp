#include<iostream>
#include<string>

#include "entities.h"
#include "handlers.h"

#include "handlers.cpp"
int main()
{
    SubMenu *mainMenu;
    mainMenu = new SubMenu("Main");
    mainMenu->add_item(new MenuItem("sample"));
    mainMenu->add_item(new MenuItem("sample"));
    mainMenu->add_item(new MenuItem("sample"));
    mainMenu->add_item(new MenuItem("sample"));
    mainMenu->run();
    return 0; 
}