#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include "Author.h"
#include "Assessment.h"
#include <vector>

// Class of Projects or Lab Report
class Project
{
    public:
    std::string name;
    Author author[10];
    std::vector <Assessment> assessments;
    std::string lab;
    std::string resume;
    std::string addresspdf;

    Project();
    Project(std::string name, Author author, std::vector <Assessment> assessments, std::string lab, std::string resume, std::string addresspdf);
    float giveRating();
    std::string editName();
    std::string editAuhtor();
};

#endif // PROJECT_H
