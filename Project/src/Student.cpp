#include "../include/Student.h"

Student:: Student(std::string name, std::string instituition, std::string course):Author(name, 1, instituition){
    this-> course= course;

}

void Student:: setArea(std::string area){
    area = course;
}

std::string Student::getArea(){
    return course;
}

Student:: ~Student(){}

std::string Student::getAuthor(){
    std::string out = "";
    out += std::to_string(role);
    out += "-";
    out += name;
    out += "-";
    out += course;
    out += "-";
    out += institution;
    return out;
}