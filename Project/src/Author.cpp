#include "Author.h"
#include <fstream>

int Author::contador = 0;

Author::Author()
{
    institution = "UFPB";
}

Author::Author(std::string name, int role, std::string institution, int id_author){
    this->name = name;
    this->role = role;
    this->institution = institution;
    this->id_author = id_author;

    std::string id = std::to_string(id_author);
    std::string contador = id.substr(1);
    contador = stoi(contador);
}

Author::Author(std::string name, int role, std::string institution){
    this->name = name;
    this->role = role;
    this->institution = institution;

    std:: string id = std::to_string(role) + std::to_string(contador);
    int id_int = std::stoi(id);
    contador ++;

    this->id_author = id_int;
}

bool Author::setName(std::string name){
    this->name = name;
    return true;
}
bool Author::setRole(int role){
    this->role = role;
}
bool Author::setInstitution(std::string institution){
    this->institution = institution;
}
bool Author::setId(int id_author){
    this->id_author = id_author;
}
std::string Author::getName(){
    return this->name;
}
int Author::getRole(){
    return this->role;
}
std::string Author::getInstitution(){
    return this->institution;
}
int Author::getId(){
    return this->id_author;
}