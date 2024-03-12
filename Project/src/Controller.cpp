#include "../include/Controller.h"
using namespace std;

Controller::Controller()
{
}

Controller::~Controller()
{
}

int Controller::indiceProjeto(string title)
{
    int tam = this->projects.size();

    for (int i = 0; i < tam; i++)
    {
        if (title == projects[i].getTitle())
        {
            return i;
        };
    }    return -1;
}

void Controller::adicionarProjeto(
    string title,
    string lab,
    string resume,
    string addresspdf)
{

    if (indiceProjeto(title) == -1){

        int cont = 0;
        char escolha;
        vector<Author> autores;

        while (true)
        {

            string name;
            int role;
            string institution;

            cout << "Adicione o nome do autor " << cont + 1 << endl;
            cin.ignore();

            getline(cin, name);

            cin >> role;
            cin.ignore();

            getline(cin, institution);

            autores.push_back(Author(name, role, institution));

            cout << name << " adicionado com sucesso!";

            cout << "Deseja cadastrar um novo autor? (S/N)";
            cin >> escolha;

            if (escolha == 'N' || escolha == 'n')
            {
                break;
            }
        }

        this->projects.push_back(Project(title, autores, lab, resume, addresspdf));
    }else{
        cout << "Um projeto com esse título já existe!";
    }
}

// Pesquisar por um projeto
int Controller::pesquisarProjeto(std::string title)
{
    int tam = projects.size();
    for (int i = 0; i < tam; i++)
    {
        if(projects[i].getTitle().find(title) != string::npos){
            
            cout << "Autor: " << projects[i].getAuthors() << endl;
            cout << "Titulo: " << projects[i].getTitle() << endl;
            cout << "Média das avaliações: " << projects[i].getAssesments() << endl;
            cout << "Laboratório de desenvolvimento: " << projects[i].getLab() << endl;
            cout << "Resumo: \n" << projects[i].getResume() << endl;
            
        }
    }
}

// Excluir um projeto
void Controller::excluirProjeto(string title)
{
    int i = indiceProjeto(title);
    
    if (indiceProjeto(title) == -1){
        cout << "Esse projeto não existe";
    }else{
        this->projects.erase(projects.begin()+i);
        cout << title << " excluido com sucesso!" << endl;
    }
}

// Editar um projeto
bool Controller::editarProjeto(int id_projeto)
{
    int o = 0;

    try
    {
        cout << "[ 1 ] Avaliar\n[ 2 ] Editar Título\n[ 3 ] Adicionar Autor\n[ 4 ] Editar Resumo\n[ 5 ] Mudar Link do PDF\n\nO que deseja fazer ? ";
        cin >> o;
        cin.ignore();
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        return false;
    }

    if(o == 0)
    {
        cout << "Função cancelada!" << endl;
        return false;
    }else if(o == 1)
    {
        string nome, instituição, comentario;
        int role, rating;

        cout << "Digite as informações do autor do comentário:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Cargo: ";
        cin >> role;
        cin.ignore();
        cout << "Instituição: ";
        getline(cin, instituição);

        Author autor_comentario = Author(nome, role, instituição);

        cout << "\nAdicione valor da avaliação [ de 1 a 5 ]: ";
        cin >> rating;
        while (rating < 1 || rating > 5)
        {
            cout << "Avaliação inválida, digite um valor válido." << endl;
            cin >> rating;
        }
        
        Assessment avaliacao = Assessment(autor_comentario, rating);

        projects[id_projeto].addAssessment(avaliacao);

        return true;
    }else if(o == 2)
    {
        string novo_titulo;
        
        cout << "Novo título: ";
        getline(cin, novo_titulo);

        projects[id_projeto].editTitle(novo_titulo);
        return true;
    }else if(o == 3)
    {
        string nome, instituição;
        int role;
        
        cout << "Digite as informações do novo autor:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Cargo: ";
        cin >> role;
        cin.ignore();
        cout << "Instituição: ";
        getline(cin, instituição);

        Author novo_autor = Author(nome, role, instituição);
        projects[id_projeto].addAuhtor(novo_autor);

        return true;
    }else if(o == 4)
    {
        string resumo;
        
        cout << "Digite novo resumo:" << endl;
        getline(cin, resumo);

        projects[id_projeto].setResume(resumo);

        return true;
    }else if(o == 5)
    {
        string endereco;

        cout << "Digite o novo endereço: ";
        getline(cin, endereco);

        projects[id_projeto].setAdresspdf(endereco);
        return true;
    }else
    {
        cout << "Não foi possível selecionar sua opção" << endl;
        return false;
    }
}

// Gerar relatório
void Controller::gerarRelatorio()
{
}

// Salvar no arquivo
bool Controller::salvar()
{
}

// Upload do arquivo
bool Controller::carregar()
{
}

// Listar todos
void Controller::listarTodos()
{
    int tam = projects.size();
    for (auto i = 0; i < tam; i++)
    {
        cout << "Autor: " << projects[i].getAuthors() << endl;
        cout << "Titulo: " << projects[i].getTitle() << endl;
        cout << "Laboratório de desenvolvimento: " << projects[i].getLab() << endl<< endl;
    }
}