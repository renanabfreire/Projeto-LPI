#include "./include/Controller.h"
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

int interface();

void mensagemDeClose();

int main(){
    Controller crud = Controller();
    int opc=0;
    bool condicao;

    cout << "\t\t -----------------------------------------------------------------" << endl;
    cout << "\t\t|                                                                 |" << endl;
    cout << "\t\t|==================== BEM VINDO AO DIVULGA-CI ====================|" << endl;
    cout << "\t\t|                                                                 |" << endl;
    cout << "\t\t -----------------------------------------------------------------" << endl;

    while(1)
    {
        opc = interface();

        if(opc == 1)
        {
            cout << "\n\nGerando seu relatório...";
            condicao = crud.gerarRelatorio();
            if(condicao == false)
            {
                cout << "Não conseguimos gerar o relatório :/\n";
                mensagemDeClose();
                break;
            }else
            {
                cout << "\n\t\t\t\t+ Relatório gerado com sucesso! +";
                getchar();
            }
            system("clear");
        }
        else if(opc == 2)
        {
            string titulo, lab, resume, addresspdf;
            cout << "\n\n  = Título: ";
            getline(cin, titulo);
            cout << "  = Laboratório: ";
            getline(cin, lab);
            cout << "  = Resumo/Abstract:\n";
            getline(cin, resume);
            cout << "  = Endereço do PDF: ";
            getline(cin, addresspdf);
            crud.adicionarProjeto(titulo, lab, resume, addresspdf);

            cout << "\t\t\t\t+ Projeto cadastrado +";
            getchar();
            system("clear");
        }
        else if(opc == 3)
        {
            string title;
            
            do{
                cout << "Digite o titulo do projeto no qual você deseja editar\n    -> ";
                getline(cin, title);
                if(crud.indiceProjeto(title) == -1)
                {
                    cout << "        - Projeto não encotrado :/ -\n        -      Tente novamente     -\n";
                }
                else
                {
                    crud.editarProjeto(title);
                    break;
                }
            } while(crud.indiceProjeto(title) == -1);

            cout << "\t\t\t\t+ Operação concluída +";
            getchar();
            system("clear");
        }

        else if(opc == 4)
        {
            string title;
            do{
                cout << "\nDigite o titulo do projeto no qual você deseja pesquisar\n    -> ";
                getline(cin, title);
                if(crud.indiceProjeto(title) == -1)
                {
                    cout << "\t\t\t\t- Projeto não encotrado :/ -\n\t\t\t\t-      Tente novamente     -\n";
                }
                else{
                    crud.pesquisarProjeto(title);
                }

            } while(crud.indiceProjeto(title) == -1);  
            getchar();
            system("clear");      
        }
        else if(opc == 5)
        {
            cout << "\n\t\tListando todos os projetos...\n\n";
            crud.listarTodos();

            getchar();
            system("clear");
        }
        else if(opc == 6)
        { 
            string title;
            cout << "\nDigite o titulo do projeto no qual você deseja excluir\n    -> ";
            getline(cin, title);

            crud.excluirProjeto(title);
            getchar();
            system("clear");
        }
        else
        {
            cout << "\n\t\t\t\t  []  Fechando programa  []\n\n";
            break;
        }
    }  
    
    return 0;
}

int interface()
{
    string opcao;
    int o=0;
    while(o<1 || o>7)
    {
        cout << "\n\n\t\t+ O que deseja fazer?" << endl;
        cout << "\n\t\t\t[ 1 ] Gerar Relatório,\n\t\t\t[ 2 ] Adicionar Projeto\n\t\t\t[ 3 ] Avaliar/Editar Projeto\n\t\t\t[ 4 ] Pesquisar Projeto\n\t\t\t[ 5 ] Listar Todos os Projetos\n\t\t\t[ 6 ] !! Excluir Projeto !!\n\t\t\t[ 7 ] Fechar programa" << endl;
        cout << "\n\t\t> Digite a sua opção: ";
        cin >> opcao;

        try
        {
            o = stoi(opcao);    
        }
        catch(const std::exception& e)
        {
            cout << "Digite um número" << '\n';
        }

        if(o<1 || o>7)
        {
            cout << "Operação não identificada, por favor, repita sua escolha..." << endl;
        }

        
        cin.ignore();
    }

    return o;
}

void mensagemDeClose()
{
    cout << "Para preservar os dados armazenados estaremos fechando o programa.\n\n[OS DADOS ARMAZENADOS SERÃO SALVOS]";
}