#include "handlers.h"
#include"system.h"

//TODO: https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
//using only linux/macOS method
#include<sys/ioctl.h>
#include <unistd.h>

void get_terminal_size(int *width, int *height)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = (int*)w.ws_col;
    height = (int*)w.ws_row;
}

std::string Menu::getTitle()
{
    return this->title;
}

void draw_separator()
{
    int width, height;
    get_terminal_size(&width, &height); // fixme
    for(int i = 0; i < 64; i++)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void SubMenu::run()
{
    system("clear");
    draw_separator();
    
}
