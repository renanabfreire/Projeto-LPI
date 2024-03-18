#include "../include/Controller.h"
using namespace std;

Controller::Controller()
{
    carregar();
}

Controller::~Controller()
{
    salvar();
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
    }
    if(title == "__PEGAR_TAM__")
    {
        return tam;
    }
    return -1;
}

void Controller::adicionarProjeto(
    string title,
    string lab,
    string resume,
    string addresspdf)
{

    if (indiceProjeto(title) == -1)
    {

        int cont = 0;
        int escolha = 1;
        vector<Author *> autores;

        while (escolha == 1)
        {

            string name;
            int role;
            string institution;

            cout << "Adicione o nome do autor " << cont + 1 << ": ";
            getline(cin, name);

            cout << "Qual cargo ele ocupa? ";
            cin >> role;
            cin.ignore();

            cout << "Qual a instituicao? ";
            getline(cin, institution);

            if (role == 1)
            {
                string course;
                cout << "Digite o curso: ";
                getline(cin, course);
                //cin.ignore();
                autores.push_back(new Student(name, institution, course));
            }
            else if (role == 2)
            {
                string departament;
                cout << "Digite o departamento: ";
                getline(cin, departament);
                //cin.ignore();
                autores.push_back(new Teacher(name, institution, departament));
            }

            cout << name << " adicionado com sucesso!" << endl;

            cout << "Deseja cadastrar um novo autor? (1-SIM/0-NAO)";
            cin >> escolha;
            cin.ignore();
            cont++;
        }

        this->projects.push_back(Project(title, autores, lab, resume, addresspdf));
    }
    else
    {
        cout << "Um projeto com esse título já existe!";
    }
}

// Pesquisar por um projeto
void Controller::pesquisarProjeto(std::string title)
{
    int tam = projects.size();
    for (int i = 0; i < tam; i++)
    {
        if (projects[i].getTitle().find(title) != string::npos)
        {

            cout << "Autor: " << projects[i].getAuthors() << endl;
            cout << "Titulo: " << projects[i].getTitle() << endl;
            cout << "Média das avaliações: " << projects[i].getAssesments() << endl;
            cout << "Laboratório de desenvolvimento: " << projects[i].getLab() << endl;
            cout << "Resumo: \n"
                 << projects[i].getResume() << endl;
        }
        
    }
}

// Excluir um projeto
void Controller::excluirProjeto(string title)
{
    int i = indiceProjeto(title);

    if (indiceProjeto(title) == -1)
    {
        cout << "  ? Esse projeto não existe ?";
    }
    else
    {
        this->projects.erase(projects.begin() + i);
        cout << title << "  + excluido com sucesso! +" << endl;
    }
}

// Editar um projeto
bool Controller::editarProjeto(string title)
{
    string opcao;
    int o = 0;

    try
    {
        cout << "[ 1 ] Avaliar\n[ 2 ] Editar Título\n[ 3 ] Adicionar Autor\n[ 4 ] Editar Resumo\n[ 5 ] Mudar Link do PDF\n\nO que deseja fazer ? ";
        cin >> opcao;
        cin.ignore();

        try
        {
            o = stoi(opcao);
        }
        catch(const std::exception& e)
        {
            cout << "Tente um valor numérico" << '\n';
        }
        
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        return false;
    }

    int id_projeto = indiceProjeto(title);

    if (o == 0)
    {
        cout << "Função cancelada!" << endl;
        return false;
    }
    else if (o == 1)
    {
        string nome, instituicao, comentario, r;
        int role, rating;

        cout << "Digite as informações do autor do comentário:" << endl;

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Cargo: ";
        cin >> role;
        cin.ignore();
        
        cout << "Instituição: ";
        getline(cin, instituicao);

        Author *autor_comentario;

        if (role == 1)
        {
            string course;
            cout << "Digite o curso: ";
            getline(cin, course);
            autor_comentario = new Student(nome, instituicao, course);
        }
        else if (role == 2)
        {
            string departament;
            cout << "Digite o departamento: ";
            getline(cin, departament);
            autor_comentario = new Teacher(nome, instituicao, departament);
        }

        cout << "\nAdicione valor da avaliação [ de 1 a 5 ]: ";
        
        while (rating < 1 || rating > 5)
        {
            cin >> r;

            try
            {
                rating = stoi(r);
            }
            catch(const std::exception& e)
            {
                cout << "Digite um valor numérico" << '\n';
            }
            
            if(rating < 1 || rating > 5)
            {
                cout << "Digite um valor válido";
            }
        }

        Assessment avaliacao = Assessment(autor_comentario, rating);

        projects[id_projeto].addAssessment(avaliacao);

        return true;
    }
    else if (o == 2)
    {
        string novo_titulo;

        cout << "Novo título: ";
        getline(cin, novo_titulo);

        projects[id_projeto].editTitle(novo_titulo);
        return true;
    }
    else if (o == 3)
    {
        string nome, instituicao;
        int role;

        cout << "Digite as informações do novo autor:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Cargo: ";
        cin >> role;
        cin.ignore();
        cout << "Instituição: ";
        getline(cin, instituicao);

        Author *novo_autor;
        if (role == 1)
        {
            string course;
            cout << "Curso: ";
            getline(cin, course);
            novo_autor = new Student(nome, instituicao, course);
        }
        else if (role == 2)
        {
            string departament;
            cout << "Departamento: ";
            getline(cin, departament);
            novo_autor = new Teacher(nome, instituicao, departament);
        }

        projects[id_projeto].addAuhtor(novo_autor);

        return true;
    }
    else if (o == 4)
    {
        string resumo;

        cout << "Digite novo resumo:" << endl;
        getline(cin, resumo);

        projects[id_projeto].setResume(resumo);

        return true;
    }
    else if (o == 5)
    {
        string endereco;

        cout << "Digite o novo endereço: ";
        getline(cin, endereco);

        projects[id_projeto].setAdresspdf(endereco);
        return true;
    }
    else
    {
        cout << "Não foi possível selecionar sua opção" << endl;
        return false;
    }
}

// Gerar relatório
bool Controller::gerarRelatorio()
{
    int cont = 0;
    float mediaDasAvaliacoes = 0, maiorAvaliacao = 0;
    string nomeMaior;

    // Gerando arquivo
    fstream relatorio;

    relatorio.open("./data/Relatório.csv", ios::out);
    if (!relatorio.is_open())
    {
        cout << "Erro: Não foi possível abrir arquivo :/" << endl;
        return false;
    }

    // primeira linha
    relatorio << "Arquivos:;Avaliações\n";

    // seguintes linhas:
    for (int i = 0; i < projects.size(); i++)
    {
        relatorio << projects[i].getTitle() << ";" << projects[i].getAssesments() << "\n";

        mediaDasAvaliacoes += projects[i].getAssesments(); // adiciona avaliação de cada projeto à média
        // salvando informações do mais bem avaliado
        if (projects[i].getAssesments() > maiorAvaliacao)
        {
            maiorAvaliacao = projects[i].getAssesments();
        }
    }

    mediaDasAvaliacoes /= projects.size();

    // fim do relatório:
    relatorio << "Avaliação média:;" << mediaDasAvaliacoes << "\n";
    relatorio << "Mais bem avaliado:;";
    for (int i = 0; i < projects.size(); i++)
    {
        if (projects[i].getAssesments() == maiorAvaliacao)
        {
            if (cont == 0)
            {
                relatorio << projects[i].getTitle() << ";" << projects[i].getAssesments() << "\n";
                cont += 1;
            }
            else
            {
                relatorio << ";" << projects[i].getTitle() << ";" << projects[i].getAssesments() << "\n";
            }
        }
    }

    return true;
}

// Salvar no arquivo
void Controller::salvar()
{
    // Create an output filestream object
    ofstream arq_projects("./data/projects.csv", ios_base::out);

    // Make sure the file is open
    if (!arq_projects.is_open())
        throw std::runtime_error("Arquivo projeto inativo!");

    // Send the column name to the stream
    arq_projects << "title; author; assessments; lab; resume; addresspdf"
                 << "\n";

    // Send data to the stream
    for (int i = 0; i < projects.size(); ++i)
    {
        arq_projects << projects[i].getTitle() << ";" << projects[i].getAuthorsComplete() << ";" << projects[i].getAssessmentsComplete() << ";" << projects[i].getLab() << ";" << projects[i].getResume() << ";" << projects[i].getAdress() << "\n";
    }

    // Close the file
    arq_projects.close();
}

// Upload do arquivo
void Controller::carregar()
{
    // Create an input filestream
    ifstream arq_projects("./data/projects.csv", ios_base::in);

    // Make sure the file is open
    if (!arq_projects.is_open())
        throw std::runtime_error("Arquivo projeto inativo!");

    // Helper vars
    string line;

    // Read the column names
    if (arq_projects.good())
    {
        // Extract the first line in the file
        getline(arq_projects, line);
    }

    // Read data, line by line
    while (getline(arq_projects, line))
    {
        string intermediario;
        stringstream informacoes(line);

        // Recebendo titulo
        getline(informacoes, intermediario, ';');
        string titulo = intermediario;

        // Recebendo autores
        getline(informacoes, intermediario, ';');

        vector<Author *> autors_vector;
        string autor;
        stringstream autores(intermediario);

        while (getline(autores, autor, ','))
        {
            stringstream atributos(autor);

            string role;
            getline(atributos, role, '-');

            string nome;
            getline(atributos, nome, '-');

            string area;
            getline(atributos, area, '-');

            string instituicao;
            getline(atributos, instituicao, '-');

            Author *novo_autor;

            int role_n;

            try {
                role_n = stoi(role);
            } catch (const std::invalid_argument& e) {
                cerr << "Error: Invalid string format for conversion to integer." << endl;
            }

            if (role_n == 1)
            {
                autors_vector.push_back(new Student(nome, instituicao, area));
            }
            else if (role_n == 2)
            {
                autors_vector.push_back(new Teacher(nome, instituicao, area));
            }
        }

        // Recebendo avaliações
        getline(informacoes, intermediario, ';');

        vector <Assessment> Assessment_vector;
        string avaliacao;
        stringstream avaliacaoes(intermediario);

        while (getline(avaliacaoes, avaliacao, ','))
        {
            stringstream atributos(avaliacao);

            string role;
            getline(atributos, role, '-');

            string nome;
            getline(atributos, nome, '-');

            string area;
            getline(atributos, area, '-');

            string instituicao;
            getline(atributos, instituicao, '-');

            string rating;
            getline(atributos, rating, '-');

            int role_n;

            try {
                role_n = stoi(role);
            } catch (const std::invalid_argument& e) {
                cerr << "Error: Invalid string format for conversion to integer." << endl;
            }

            Author *novo_autor;
            if (role_n == 1)
            {
                novo_autor = new Student(nome, instituicao, area);
            }
            else if (role_n == 2)
            {
                novo_autor = new Teacher(nome, instituicao, area);
            }

            int rating_n;

            try {
                rating_n = stoi(rating);
            } catch (const std::invalid_argument& e) {
                cerr << "Error: Invalid string format for conversion to integer." << endl;
            }

            Assessment_vector.push_back(Assessment(novo_autor, rating_n));
        }

        // Recebendo lab, resume e addresspdf
        getline(informacoes, intermediario, ';');
        string lab = intermediario;

        getline(informacoes, intermediario, ';');
        string resume = intermediario;

        getline(informacoes, intermediario, ';');
        string addresspdf = intermediario;

        projects.push_back(Project(titulo, autors_vector, Assessment_vector, lab, resume, addresspdf));
    }

    // Close file
    arq_projects.close();
}

// Listar todos
void Controller::listarTodos()
{
    int tam = projects.size();
    for (auto i = 0; i < tam; i++)
    {
        cout << "Autor: " << projects[i].getAuthors() << endl;
        cout << "Titulo: " << projects[i].getTitle() << endl;
        cout << "Laboratório de desenvolvimento: " << projects[i].getLab() << endl
             << endl;
    }
}