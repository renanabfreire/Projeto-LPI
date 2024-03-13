#include "Author.h"
#include <string>
using namespace std;

class Teacher: public Author{

    protected:
    string departament;

    public:
    Teacher();
    Teacher(string name, string instituition, string departament);
    ~Teacher();
    void setArea(string area);
    string getArea();


};