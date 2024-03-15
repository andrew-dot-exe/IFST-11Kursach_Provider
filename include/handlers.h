/*
    Прототип классов меню.
    (c) andrew_dot_exe, 2024.
*/
#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<functional>

class Menu
{
private:
    std::string title;
public:
    Menu(std::string title) : title(title){}
    std::string getTitle();
    virtual void run() = 0;
};

class SubMenu : public Menu
{
private:
    std::vector<Menu*> items;

public:
   // SubMenu(std::string title) : title(title){}
    void add_item(Menu* item);
    void run() override;

};

class MenuItem : public Menu
{
public:
	void run() override;
private:
	std::function<void()> action; // нужны флаги компиляции -std=c++11 -stdlib=libc++
};