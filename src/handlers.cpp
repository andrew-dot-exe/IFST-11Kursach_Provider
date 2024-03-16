#include "handlers.h"
#include"system.h"

// todo: set terminal to 90 chars width

void draw_separator()
{
    int width, height;
   // get_terminal_size(&width, &height); // fixme
    for(int i = 0; i < TERMINAL_WIDTH; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void draw_header(std::string custom_text = "")
{
    if(custom_text != "")
    {
        std::cout << custom_text << std::endl;
    }
    else{
    std::cout << R"(
  ___            _                       _____                                 _     
 / _ \          | |                     /  __ \                               | |    
/ /_\ \_ __   __| |_ __ _____      _____| /  \/ ___  _   _ _ __ ___  __ _  ___| |__  
|  _  | '_ \ / _` | '__/ _ \ \ /\ / / __| |    / _ \| | | | '__/ __|/ _` |/ __| '_ \ 
| | | | | | | (_| | | |  __/\ V  V /\__ \ \__/\ (_) | |_| | |  \__ \ (_| | (__| | | |
\_| |_/_| |_|\__,_|_|  \___| \_/\_/ |___/\____/\___/ \__,_|_|  |___/\__,_|\___|_| |_|
                                                                                     
                                                                                     		
)" << '\n';
    }
}

void SubMenu::add_item(Menu* item)
{
    this->items.push_back(item);
}

std::string Menu::getTitle()
{
    return this->title;
}

void SubMenu::print_menu()
{
    for(size_t i = 0; i < this->items.size(); i++)
    {
        std::cout << i << " " <<this->items[i]->getTitle() << std::endl;
    }
    std::cout << COLOR_RED << "Нажмите q для выхода из меню." << COLOR_BREAK <<std::endl;
}

int SubMenu::readChoice()
{
    std::string choice;
    std::cout << "Введите номер пункта меню ";
    std::cin >> choice;
    if(choice == "q")
    {
        system(CLEAR_SCR);
        return -1;
    }
    int chse = std::stoi(choice);
    return chse;
    //case special exit info
}

void SubMenu::executeFunction(int choice)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(i == choice)
        {
            items[i]->run();
        }
    }
}

void SubMenu::postFunction()
{
    if(entryCount == maxEntryCount)
    {
        system(CLEAR_SCR); // очищаем экран после двух входов в меню
        entryCount = 0;
    }
    else
    {
        std::cout << "\n";
        for (int i = 0; i < TERMINAL_WIDTH; i++)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

void SubMenu::run()
{
    system(CLEAR_SCR); // todo: replace with system.h constants.
    //std::cout << BACKGROUND_BLUE;
    while (1)
    {
        draw_separator();
        draw_header(header); //todo: custom text
        draw_separator();
        print_menu();
        int choice = readChoice();     
        if (choice == -1)
        {
            break;
        }
        executeFunction(choice);
        entryCount += 1;

        postFunction();
    }
}

void MenuItem::run()
{
    // call action
    system("clear");
    std::cout << COLOR_RED << "placeholder" << COLOR_BREAK << std::endl;
    return;
}
