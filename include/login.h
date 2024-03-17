/*
    Прототипы работы многопользовательского режима.
    (c) andrew_dot_exe, 2024.
*/

#pragma once

#include <string>
#include <iostream>
#include <vector>

class User
{
    // ВАЖНО: это прототип пользователя ИС, не клиента.
    // Он содержится в отдельном файле users.dat и
    // предназначен для обеспечения разграничения
    // доступа к ИС.

private:
    std::string login;
    std::string password;
    bool hasLogged = false; //?
    bool adminPrivs;        // если true - то имеет возможность редактирования, удаления записей.
public:
    User(std::string login, std::string password, bool adminPrivs = false);
    void authorize(std::string login, std::string password);
    bool getLogged();
    bool getAdminPrivs();
    std::string getLogin();
};

//todo: userDataHandler
class UserHandler
{
    // Этот класс реализует поиск пользователя из списка пользователей
    // и возвращает (указатель?) пользователя.   
private:
    inline static std::vector<User*> _userList{};
public:
    static void load(std::vector<User*> users);
    static User* getUser(std::string *login, std::string *password);
};