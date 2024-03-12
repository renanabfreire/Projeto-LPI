#include "../include/Project.h"

Project::Project()
{
}

Project::Project(std::string name, std::vector <Author> author, std::vector <Assessment> assessments, std::string lab, std::string resume, std::string addresspdf)
{
    this->name = name;
    this->author = author;
    this->assessments = assessments;
    this->lab = lab;
    this->resume = resume;
    this->addresspdf = addresspdf;
}

bool Project::editName(std::string name)
{
    try
    {
        this->name = name;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}

bool Project::addAuhtor(Author author)
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

std::string Project::getName()
{
    return name;
}


std::string Project::getAuthors()
{
    std::string out="";
    int tam = author.size();

    for(int i=0; i<tam; i++)
    {
        out += author[i].getName();
        if(i<(tam-1))
        {
            out += ", ";
        }
    }

    return out;
}


/*std::vector Project::getAssesments()
{
    return assessments;
}*/


std::string Project::getLab()
{
    return lab;
}


std::string Project::getResume()
{
    return resume;
}
