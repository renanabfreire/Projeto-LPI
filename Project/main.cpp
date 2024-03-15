#include "../include/Controller.h"
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
            }
            break;
        }
        else if(opc == 2)
        {
            string titulo, lab, resume, addresspdf;
            cout << "\n\n Título: ";
            getline(cin, titulo);
            cout << "Laboratório: ";
            getline(cin, lab);
            cout << "Resumo/Abstract:\n";
            getline(cin, resume);
            cout << "Endereço do PDF: ";
            getline(cin, addresspdf);
            crud.adicionarProjeto(titulo, lab, resume, addresspdf);
        }
    }    
    
    return 0;
}

int interface()
{
    int o=0;
    while(o<1 || o>5)
    {
        cout << "\n\n   + O que deseja fazer?" << endl;
        cout << "     [ 1 ] Gerar Relatório,\n     [ 2 ] Adicionar Projeto\n     [ 3 ] Avaliar/Editar Projeto\n     [ 4 ] Pesquisar Projeto\n     [ 5 ] !! Excluir Projeto !!\n" << endl;
        cout << "Digite a sua opoção: ";
        cin >> o;

        if(o<1 || o>5)
        {
            cout << "Operação não identificada, por favor, repita sua escolha..." << endl;
        }

    }
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