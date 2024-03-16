#include "./include/Controller.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<Author*> author;

    author.push_back(new Student("Joao", "UFABC", "Engenharia"));
    author.push_back(new Teacher("Maria", "UFCAB", "Matematica"));

    for (int i = 0; i < author.size(); i++)
    {
        cout << author[i]->getAuthor() << endl;
    }

    Assessment aa = Assessment(author[0], 1);
    Assessment bb = Assessment(author[1], 5);

    //cout << bb.getAuthor();

    Project a = Project("title", author, "lab", "resume", "addresspdf");
    cout << a.getAuthorsComplete() << endl;

    a.addAssessment(aa);
    a.addAssessment(bb);

    cout << "Asses: " << a.getAssessmentsComplete();

    /* Controller sistema = Controller();

    sistema.adicionarProjeto("que cachorro eh esse", "topdosbichos", "auaua", "googe.com");
    sistema.adicionarProjeto("que gatinho eh esse", "topdosbichos2", "miaumiau", "gatinho.com");

    sistema.salvar(); */
}