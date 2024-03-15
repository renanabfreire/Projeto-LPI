#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>

// Class of Author
class Author
{
    protected:
        int role;
        std::string name;
        std::string institution;

    public:
        Author(std::string name, int role, std::string institution);
        ~Author();

        //Funções para edição dos autores
        void setName(std::string name);
        virtual void setArea(std::string area) = 0;
        void setInstitution(std::string institution);
        void setRole(int role);
        std::string getName();
        virtual std::string getArea() = 0;
        std::string getInstitution();
        int getRole();
        virtual std::string getAuthor() = 0;
};

#endif // AUTHOR_H
