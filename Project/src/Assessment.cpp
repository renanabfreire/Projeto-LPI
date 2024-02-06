#include "Assessment.h"

Assessment::Assessment()
{
}

Assessment::Assessment(Author avaliador, int rating, std::string comment){

    if (rating < 1 || rating > 5){
        throw std::invalid_argument("A avaliacao deve ser de 1 a 5");
    }
    
    this->avaliador = avaliador;
    this->rating = rating;
    this->comment = comment;
}

bool Assessment::editAuhtor(Author avaliador)
{
    try
    {
        this->avaliador = avaliador;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
};

bool Assessment::editRating(int rating)
{
    try
    {
        this->rating = rating;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
};

bool Assessment::editComment(std::string comment)
{
    try
    {
        this->comment = comment;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
};
