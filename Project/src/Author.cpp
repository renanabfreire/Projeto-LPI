#include "Author.h"

Author::Author()
{
    institution = "UFPB";
}

Author::Author(std::string name, std::string course_department, int role, std::string institution, int id){
    this->name = name;
    this->course_department = course_department;
    this->role = role;
    this->institution = institution;
    this->id = id;
}

