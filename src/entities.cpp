#include "entities.h"

Document::Document(int document_id, std::string info)
{
    this->documentID = document_id;
    this->documentInfo = info;
}

int Document::getDocumentID() { return this->documentID; }

std::string Document::getDocumentInfo() { return this->documentInfo; }

