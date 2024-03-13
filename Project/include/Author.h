#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>

// Class of Author
class Author
{
    private:
        std::string name;
        std::string institution;

    public:
        Author();

        //Funções para edição dos autores
        bool setName(std::string name);
        virtual void setArea(std::string area) = 0;
        bool setInstitution(std::string institution);
        std::string getName();
        virtual string getArea() = 0;
        std::string getInstitution();
};

#endif // AUTHOR_H
