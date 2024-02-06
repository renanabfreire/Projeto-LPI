#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include "Author.h"
#include <string>
#include <iostream>

// Class of Assessments
class Assessment
{
    public:
        Author avaliador;
        int rating;
        std:: string comment;

    Assessment();
    Assessment(Author avaliador, int rating, std::string comment);

    // Funcoes para edição das avaliações
    bool editAuhtor(Author avaliador);
    bool editRating(int rating);
    bool editComment(std::string comment);

};

#endif // ASSESSMENT_H