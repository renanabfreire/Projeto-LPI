#include "Author.h"
#include <fstream>

Author::Author()
{
    institution = "UFPB";
}

Author::Author(std::string name, int role, std::string institution, int id){
    this->name = name;
    this->role = role;
    this->institution = institution;
    this->id = id;
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
bool Author::setId(int id){
    this->id = id;
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
    return this->id;
}