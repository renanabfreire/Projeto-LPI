#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include "Author.h"
#include <string>

// Class of Assessments
class Assessment
{
    public:

        Author avaliador;
        int rating;
        std:: string comment;

    Assessment();
};

#endif // ASSESSMENT_H