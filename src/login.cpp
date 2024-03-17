#include "login.h"

User::User(std::string login, std::string password, bool adminPrivs)
{
    this->login = login;
    this->password = password;
    this->adminPrivs = adminPrivs;
}

void User::authorize(std::string login, std::string password)
{
    if(this->login == login && this->password == password)
    {
        hasLogged = true;
    }
}

bool User::getLogged()
{
    return this->hasLogged;
}

bool User::getAdminPrivs()
{
    return this->adminPrivs;
}

std::string User::getLogin()
{
    return login;
}

void UserHandler::load(std::vector< User*> users)
{
    _userList = users;
}

User* UserHandler::getUser(std::string *login, std::string *password)
{
    for(int i = 0; i < _userList.size(); i++)
    {
        if(*login == _userList[i]->getLogin())
        {
            _userList[i]->authorize(*login, *password);
            if(_userList[i]->getLogged())
            {
                return _userList[i];
            }
        }
    }   
    return nullptr;
}