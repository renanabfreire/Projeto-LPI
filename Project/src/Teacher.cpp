#include "../include/Teacher.h"

Teacher:: Teacher(string name, string instituition, string departament):Author(name, 2, instituition){
    this->departament= departament;
}

void Teacher:: setArea(std::string area){
    area = departament;
}

string Teacher:: getArea(){
    return departament;
}

Teacher:: ~Teacher(){}

std::string Teacher::getAuthor(){
    std::string out = "";
    out += std::to_string(role);
    out += "-";
    out += name;
    out += "-";
    out += departament;
    out += "-";
    out += institution;
    return out;
}