#include "Author.h"
#include <fstream>


Author::Author()
{
    institution = "UFPB";
}

Author::Author(std::string name, int role, std::string institution){
    this->name = name;
    this->role = role;
    this->institution = institution;
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
std::string Author::getName(){
    return this->name;
}
int Author::getRole(){
    return this->role;
}
std::string Author::getInstitution(){
    return this->institution;
}