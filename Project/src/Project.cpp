#include "../include/Project.h"

Project::Project()
{
}

Project::~Project(){}

Project::Project(std::string title, std::vector <Author*> author, std::vector <Assessment> assessments, std::string lab, std::string resume, std::string addresspdf)
{
    this->title = title;
    this->assessments = assessments;
    this->lab = lab;
    this->resume = resume;
    this->addresspdf = addresspdf;
    this->author = author;
}

Project::Project(std::string title, std::vector <Author*> author, std::string lab, std::string resume, std::string addresspdf)
{
    this->title = title;
    this->author = author;
    this->lab = lab;
    this->resume = resume;
    this->addresspdf = addresspdf;
}


bool Project::editTitle(std::string title)
{
    try
    {
        this->title = title;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

bool Project::addAuhtor(Author *author)
{
    try
    {
        this->author.push_back(author);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

bool Project::addAssessment(Assessment assessment)
{
    try
    {
        assessments.push_back(assessment);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

bool Project::setLab(std::string laboratorio)
{
    try
    {
        lab = laboratorio;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

bool Project::setResume(std::string resume)
{
    try
    {
        this->resume = resume;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}


bool Project::setAdresspdf(std::string address)
{
    try
    {
        addresspdf = address;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

std::string Project::getTitle()
{
    return title;
}


std::string Project::getAuthors()
{
    std::string out="";
    int tam = author.size();

    for(int i=0; i<tam; i++)
    {
        out += author[i]->getName();
        if(i<(tam-1))
        {
            out += ", ";
        }
    }

    return out;
}


float Project::getAssesments()
{
    float media = 0;
    for(int i=0; i<assessments.size();i++)
    {
        media += assessments[i].rating;
    }
    return media/assessments.size();
}

std::string Project::getAssessmentsComplete(){

    std::string out= "";

    for(int i=0; i<assessments.size(); i++)
    {
        out += assessments[i].getAuthor();
        out += "-";
        out += to_string(assessments[i].rating);
        if (i != assessments.size()-1){
            out += ",";
        }
    }

    return out;
}


std::string Project::getLab()
{
    return lab;
}


std::string Project::getResume()
{
    return resume;
}

std::string Project::getAdress()
{
    return addresspdf;
}

std::string Project::getAuthorsComplete(){

    std::string out= "";

    for(int i=0; i<author.size(); i++)
    {
        int role = author[i]->getRole();
        cout << role;
        out += to_string(role);
        out += "-";
        out += author[i]->getName();
        out += "-";
        out += author[i]->getArea();
        out += "-";
        out += author[i]->getInstitution();
        if (i != author.size()-1){
            out += ",";
        }
    }
    return out; 
}
