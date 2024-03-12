#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <vector>
#include <iostream>
#include "Assessment.h"
#include "Author.h"
#include "Login.h"
#include "Project.h"

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
        int pesquisarProjeto(std::string titulo);

        // Validar existencia do projeto
        int indiceProjeto(std::string title);

        // Excluir um projeto
        void excluirProjeto(std::string title);

        // Editar um projeto
        bool editarProjeto(int id_projeto);

        // Gerar relatório
        void gerarRelatorio();

        // Salvar no arquivo
        bool salvar();

        // Upload do arquivo
        bool carregar();

        // Listar todos
        void listarTodos();
        
        // Construtor
        Controller();

        // Destrutor
        ~Controller();
};

#endif // CONTROLLER_H