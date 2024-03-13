#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include "Author.h"
#include <string>
#include <iostream>

// Class of Assessments
class Assessment
{
    public:
        Author *avaliador;
        int rating;

    Assessment();
    Assessment(Author avaliador, int rating);

    // Funcoes para edição das avaliações
    bool editAuhtor(Author avaliador);
    bool editRating(int rating);
};

#endif // ASSESSMENT_H