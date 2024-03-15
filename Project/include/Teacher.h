#include "Author.h"
#include <string>
using namespace std;

class Teacher: public Author{
    private:
        string departament;

    public:
        Teacher(string name, string instituition, string departament);
        ~Teacher();
        void setArea(string area);
        string getArea();
};