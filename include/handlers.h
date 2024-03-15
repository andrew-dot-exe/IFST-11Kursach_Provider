/*
    Прототип классов меню.
    (c) andrew_dot_exe, 2024.
*/
#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<functional>
#include<typeinfo> //зачем??

class Menu
{
protected:
    std::string title;
public:
    Menu(std::string title) : title(title){};
    std::string getTitle();
    virtual ~Menu(){}
    virtual void run() {};
};

class SubMenu : public Menu
{
private:
    std::vector<Menu*> items;

public:
    virtual ~SubMenu(){};
    SubMenu(std::string title): Menu(title) { this->title = title;}
    void add_item(Menu* item);
    void print_menu();
    void run() override;

};

class MenuItem : public Menu
{
public:
    MenuItem(std::string title): Menu(title) { this->title = title;}
	void run() override;
    virtual ~MenuItem(){}
private:
	std::function<void()> action; // нужны флаги компиляции -std=c++11 -stdlib=libc++
};