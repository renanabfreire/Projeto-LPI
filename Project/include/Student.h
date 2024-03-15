#include "Author.h"

class Student : public Author{

    private:
        std::string course;

    public:
        Student(std::string name, std::string instituition, std::string course);
        ~Student();
        void setArea(std::string course);
        std::string getArea();
};