#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include "Author.h"

// Class of Projects or Lab Report
class Project
{
    public:
    std::string name;
    Author author;
    float rating;
    std::string lab;
    std::string resume;
    std::string addresspdf;

    Project();
    float giveRating();
    std::string editName();
    std::string editAuhtor();
};

#endif // PROJECT_H
