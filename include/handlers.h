#include "entities.h"

class InputHandler
{
    public:
        static Client addNewClient();
        static Document addNewDocument();
};

class MainHandler
{
    public:
        MainHandler();
        MainHandler(std::string basePath);
        
};
