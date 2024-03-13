#include "Student.h"

Student:: Student(){}

Student:: Student(string name, string instituition, string course){

    setName(name);
    setInstitution(instituition);
    this-> course= course;

}

void Student:: setArea(std::string area){
    area= course;
}

string Student:: getArea(){
    return course;
}

Student:: ~Student(){}