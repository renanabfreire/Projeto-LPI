#include "Teacher.h"

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