#ifndef AUTHOR_H
#define AUTHOR_H
#include <string>

// Class of Author
class Author
{
    public:

        std::string name;
        std::string course_department;
        int role;
        std::string institution;
        int id;

    Author();
    Author(std::string name, std::string course_department, int role, std::string institution, int id);

    //Funções para edição dos autores
    bool editName(std::string name);
    bool editCourse(std::string course_department);
    bool editRole(int role);
    bool editInstitution(std::string institution);
    bool editId(int id);
};

#endif // AUTHOR_H
