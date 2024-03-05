#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>

// Class of Author
class Author
{
    private:
        std::string name;
        int role;
        std::string institution;
        int id;

    public:
        Author();
        Author(std::string name, int role, std::string institution, int id);

        //Funções para edição dos autores
        bool setName(std::string name);
        bool setRole(int role);
        bool setInstitution(std::string institution);
        bool setId(int id);
        std::string getName();
        int getRole();
        std::string getInstitution();
        int getId();
};

#endif // AUTHOR_H
