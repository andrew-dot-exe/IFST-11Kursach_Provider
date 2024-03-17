#include<iostream>
#include<string>
#include<vector>

#include "entities.h"
#include "handlers.h"
#include "login.h"


void menuTest()
{
    SubMenu *mainMenu;
    SubMenu *childMenu;

    mainMenu = new SubMenu("Main");
    childMenu = new SubMenu("Child", "Parent Header");

    childMenu->add_item(new MenuItem("sample from parent"));

    mainMenu->add_item(new MenuItem("sample parent"));
    mainMenu->add_item(childMenu);
    mainMenu->run();
}

void userTest()
{
    std::vector<User*> list;
    list.push_back(new User("andrew", "deimos"));
    list.push_back(new User("ivan", "neptune"));
    list.push_back(new User("kirrill", "phobos"));
    list.push_back(new User("abuse", "21123"));
    UserHandler::load(list);
    std::string sample_login = "andrew";
    std::string sample_psw = "deimos";
    User *currentUser = UserHandler::getUser(&sample_login, &sample_psw);
    return;
}

int main()
{
    userTest();
    return 0; 
}