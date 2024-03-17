#include "./include/Controller.h"
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

int interface();

void carregamento();

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
            cout << "\n\nGerando seu relatório";
            condicao = crud.gerarRelatorio();
            carregamento();
            if(condicao == false)
            {
                cout << "Não conseguimos gerar o relatório :/\n";
                mensagemDeClose();
                break;
            }else
            {
                cout << "  + Relatório gerado com sucesso! +";
                getchar();
            }
        }
        else if(opc == 2)
        {
            cin.ignore();
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
            cin.ignore();

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
                }
            } while(crud.indiceProjeto(title) == -1);

            cout << "  + Operação concluída +";
            getchar();
        }

        else if(opc == 4)
        {
            cin.ignore();
            string title;
            do{
                cout << "Digite o titulo do projeto no qual você deseja pesquisar\n    -> ";
                getline(cin, title);
                if(crud.indiceProjeto(title) == -1)
                {
                    cout << "        - Projeto não encotrado :/ -\n        -      Tente novamente     -";
                }
                else{
                    crud.pesquisarProjeto(title);
                }

            } while(crud.indiceProjeto(title) == -1);        
        }
        else if(opc == 5)
        { 
            cin.ignore();
            
            string title;
            cout << "Digite o titulo do projeto no qual você deseja excluir\n    -> ";
            getline(cin, title);

            crud.excluirProjeto(title);
            getchar();
        }
        else
        {
            cout << "    []  Fechando programa  []" << endl;
            carregamento();
            break;
        }
    }  
    
    return 0;
}

int interface()
{
    int o=0;
    while(o<1 || o>6)
    {
        cout << "\n\n   + O que deseja fazer?" << endl;
        cout << "     [ 1 ] Gerar Relatório,\n     [ 2 ] Adicionar Projeto\n     [ 3 ] Avaliar/Editar Projeto\n     [ 4 ] Pesquisar Projeto\n     [ 5 ] !! Excluir Projeto !!\n     [ 6 ] Fechar programa" << endl;
        cout << "Digite a sua opção: ";
        cin >> o;

        if(o<1 || o>6)
        {
            cout << "Operação não identificada, por favor, repita sua escolha..." << endl;
        }
    }

    return o;
}

void carregamento()
{
    sleep(0.5);
    cout << ".";
    sleep(0.5);
    cout << ".";
    sleep(0.5);
    cout << ".";
}

void mensagemDeClose()
{
    cout << "Para preservar os dados armazenados estaremos fechando o programa.\n\n[OS DADOS ARMAZENADOS SERÃO SALVOS]";
}