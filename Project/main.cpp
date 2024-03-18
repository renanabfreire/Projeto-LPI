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

    cout << " -----------------------------------------------------------------" << endl;
    cout << "|==================== BEM VINDO AO DIVULGA-CI ====================|" << endl;
    cout << " -----------------------------------------------------------------" << endl;

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
                cout << "\n  + Relatório gerado com sucesso! +";
                getchar();
            }
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

            cout << "  + Projeto cadastrado +";
            getchar();
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

            cout << "  + Operação concluída +";
            getchar();
        }

        else if(opc == 4)
        {
            string title;
            do{
                cout << "Digite o titulo do projeto no qual você deseja pesquisar\n    -> ";
                getline(cin, title);
                if(crud.indiceProjeto(title) == -1)
                {
                    cout << "        - Projeto não encotrado :/ -\n        -      Tente novamente     -\n";
                }
                else{
                    crud.pesquisarProjeto(title);
                }

            } while(crud.indiceProjeto(title) == -1);        
        }
        else if(opc == 5)
        {
            cout << "Listando todos os projetos...\n";
            crud.listarTodos();

            getchar();
        }
        else if(opc == 6)
        { 
            string title;
            cout << "Digite o titulo do projeto no qual você deseja excluir\n    -> ";
            getline(cin, title);

            crud.excluirProjeto(title);
            getchar();
        }
        else
        {
            cout << "    []  Fechando programa  []\n";
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
        cout << "\n\n   + O que deseja fazer?" << endl;
        cout << "     [ 1 ] Gerar Relatório,\n     [ 2 ] Adicionar Projeto\n     [ 3 ] Avaliar/Editar Projeto\n     [ 4 ] Pesquisar Projeto\n     [ 5 ] Listar Todos os Projetos\n     [ 6 ] !! Excluir Projeto !!\n     [ 7 ] Fechar programa" << endl;
        cout << "Digite a sua opção: ";
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