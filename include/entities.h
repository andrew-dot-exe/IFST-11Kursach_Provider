#include <string>

class Client
{
private:
    int personalID;       // ID записи пользователя
    std::string fullName; // фаимилия и имя
    int documentID; // ID договора на указание услуг

public:
    Client(std::string fullname, int personalID, int documentID);
    std::string getName();
    int getPersonalID();
};

class Document
{
private:
    int documentID; // ID документа
    std::string documentInfo; //информация о документе

public:
    int getDocumentID();
    std::string getDocumentInfo;
};
