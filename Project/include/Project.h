#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <vector>
#include "../include/Author.h"
#include "../include/Assessment.h"
#include "../include/Student.h"
#include "../include/Teacher.h"

// Class of Projects or Lab Report
class Project
{
    private:
    std::string title;
    std::vector <Author*> author;
    std::vector <Assessment> assessments;
    std::string lab;
    std::string resume; 
    std::string addresspdf;

    public:
    Project();
    Project(std::string title, std::vector <Author*> author, std::string lab, std::string resume, std::string addresspdf);
    Project(std::string title, std::vector <Author*> author, std::vector <Assessment> assessments, std::string lab, std::string resume, std::string addresspdf);
    ~Project();
    bool editTitle(std::string title);
    bool addAuhtor(Author *author);
    bool addAssessment(Assessment assessment);
    bool setLab(std::string laboratorio);
    bool setResume(std::string resume);
    bool setAdresspdf(std::string address);
    std::string getTitle();
    std::string getAuthors();
    float getAssesments();
    std::string getAssessmentsComplete();
    std::string getLab();
    std::string getResume();
    std::string getAdress();
    std::string getAuthorsComplete();
};

#endif // PROJECT_H
