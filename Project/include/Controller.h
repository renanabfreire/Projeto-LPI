#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <ctype.h>
#include "Assessment.h"
#include "Author.h"
#include "Project.h"
#include "Student.h"
#include "Teacher.h"

class Controller{

        private:
        std::vector <Project> projects;

    public:
        // Adicionar um projeto a primeira vez
        void adicionarProjeto(
            std::string title,
            std::string lab, 
            std::string resume, 
            std::string addresspdf
        );

        // Pesquisar por um projeto
        void pesquisarProjeto(std::string titulo);

        // Validar existencia do projeto
        int indiceProjeto(std::string title);

        // Excluir um projeto
        void excluirProjeto(std::string title);

        // Editar um projeto
        bool editarProjeto(std::string title);

        // Gerar relatório
        bool gerarRelatorio();

        // Salvar no arquivo
        void salvar();

        // Upload do arquivo
        void carregar();

        // Listar todos
        void listarTodos();
        
        // Construtor
        Controller();

        // Destrutor
        ~Controller();
};

#endif // CONTROLLER_H