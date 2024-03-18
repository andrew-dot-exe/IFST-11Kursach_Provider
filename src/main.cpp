#include<iostream>
#include<string>
#include<vector>

#include "entities.h"
#include "handlers.h"
#include "login.h"


std::vector<User*> getTestUserInfo()
{
    std::vector<User*> list;
    list.push_back(new User("andrew", "deimos", true)); // admin
    list.push_back(new User("ivan", "neptune"));
    list.push_back(new User("kirrill", "phobos"));
    list.push_back(new User("abuse", "21123"));
    return list;    
}

void menuTest()
{
    SubMenu *mainMenu;
    SubMenu *childMenu;

    mainMenu = new SubMenu("Main");
    childMenu = new SubMenu("Child", "Parent Header", true);

    childMenu->add_item(new MenuItem("sample from parent", true));

    mainMenu->add_item(new MenuItem("sample parent"));
    mainMenu->add_item(childMenu);
    mainMenu->run();
}

void correctLoginTest()
{
    std::string sample_login = "andrew";
    std::string sample_psw = "deimos";
    User *currentUser = UserHandler::getUser(&sample_login, &sample_psw);
    if(currentUser == nullptr)
    {
        std::cout << "user not found!" << std::endl;
    }
    else
    {
        if(currentUser->getLogged())
        {
            std::cout << "user logged in" << std::endl;
        } 
        std::cout << "test passed" << std::endl;
    }
}

void admin_login_menu()
{
    std::string sample_login = "andrew";
    std::string sample_psw = "deimos";
    User *currentUser = UserHandler::getUser(&sample_login, &sample_psw);
    if(currentUser->getLogged() && currentUser->getAdminPrivs())
    {
            menuTest(); // menu callout with admin rights
            std::cout << "Menu for admins test passed!\n";
    }
    return;
}

void userTest()
{
    UserHandler::load(getTestUserInfo());
    correctLoginTest();
    admin_login_menu();
    return;
}

int main()
{
    userTest();
    return 0; 
}

