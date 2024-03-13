#include "Teacher.h"

Teacher:: Teacher(){}

Teacher:: Teacher(string name, string instituition, string departament){
    setName(name);
    setInstitution(instituition);
    this->departament= departament;

}

void Teacher:: setArea(std::string area){
    area= departament;
}

string Teacher:: getArea(){
    return departament;
}

Teacher:: ~Teacher(){}