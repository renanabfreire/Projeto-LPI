#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include "Author.h"
#include "Assessment.h"
#include <vector>

// Class of Projects or Lab Report
class Project
{
    private:
    std::string name;
    std::vector <Author> author;
    std::vector <Assessment> assessments;
    std::string lab;
    std::string resume;
    std::string addresspdf;

    public:
    Project();
    Project(std::string name, std::vector <Author> author, std::vector <Assessment> assessments, std::string lab, std::string resume, std::string addresspdf);
    bool editName(std::string name);
    bool addAuhtor(Author autor);
    bool addAssessment(Assessment assessment);
    bool setLab(std::string laboratorio);
    bool setResume(std::string resume);
    bool setAdresspdf(std::string address);
    std::string getName();
    std::string getAuthors();
    std::string getAssesments();
    std::string getLab();
    std::string getResume();
};

#endif // PROJECT_H
