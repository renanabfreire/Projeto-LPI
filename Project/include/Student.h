#include "Author.h"

class Student : public Author{

    protected:
    string course;

    public:
    Student();
    Student(string name, string instituition, string course);
    ~Student();
    void setArea(area);
    string getArea();


};