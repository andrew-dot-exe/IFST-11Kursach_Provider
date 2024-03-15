#include "handlers.h"
#include"system.h"

// todo: set terminal to 90 chars width

void draw_separator()
{
    int width, height;
   // get_terminal_size(&width, &height); // fixme
    for(int i = 0; i < 90; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void draw_header()
{
    std::cout << R"(
  ___            _                       _____                                 _     
 / _ \          | |                     /  __ \                               | |    
/ /_\ \_ __   __| |_ __ _____      _____| /  \/ ___  _   _ _ __ ___  __ _  ___| |__  
|  _  | '_ \ / _` | '__/ _ \ \ /\ / / __| |    / _ \| | | | '__/ __|/ _` |/ __| '_ \ 
| | | | | | | (_| | | |  __/\ V  V /\__ \ \__/\ (_) | |_| | |  \__ \ (_| | (__| | | |
\_| |_/_| |_|\__,_|_|  \___| \_/\_/ |___/\____/\___/ \__,_|_|  |___/\__,_|\___|_| |_|
                                                                                     
                                                                                     		
)" << '\n';
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
        std::cout << this->items[i]->getTitle() << std::endl;
    }
}

void SubMenu::run()
{
    system("clear"); //todo: replace with system.h constants.
    draw_separator();
    draw_header();
    draw_separator();
    print_menu();
}

void MenuItem::run()
{
    // call action
    std::cout << "placeholder" << std::endl;
    return;
}
