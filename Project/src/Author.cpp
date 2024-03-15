#include "../include/Author.h"

Author::Author(std::string name, int role, std::string institution){
    this->name = name;
    this->role = role;
    this->institution = institution;
}

Author::~Author(){}

void Author::setName(std::string name){
    this->name = name;
}
void Author::setRole(int role){
    this->role = role;
}
void Author::setInstitution(std::string institution){
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