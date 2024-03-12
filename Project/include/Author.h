#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>

// Class of Author
class Author
{
    private:
        static int contador;
        std::string name;
        int role;
        std::string institution;
        int id_author;

    public:
        Author();
        Author(std::string name, int role, std::string institution, int id_author);
        Author(std::string name, int role, std::string institution);

        //Funções para edição dos autores
        bool setName(std::string name);
        bool setRole(int role);
        bool setInstitution(std::string institution);
        bool setId(int id_author);
        std::string getName();
        int getRole();
        std::string getInstitution();
        int getId();
};

#endif // AUTHOR_H
