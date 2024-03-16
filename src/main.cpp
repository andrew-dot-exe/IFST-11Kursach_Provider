#include<iostream>
#include<string>

#include "entities.h"
#include "handlers.h"

#include "handlers.cpp"
int main()
{
    SubMenu *mainMenu;
    SubMenu *childMenu;

    mainMenu = new SubMenu("Main");
    childMenu = new SubMenu("Child", "Parent Header");

    childMenu->add_item(new MenuItem("sample from parent"));

    mainMenu->add_item(new MenuItem("sample parent"));
    mainMenu->add_item(childMenu);
    mainMenu->run();
    return 0; 
}