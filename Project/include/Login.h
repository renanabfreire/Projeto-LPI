#pragma once
#include <string>

class Login
{
    private:
    
        std::string user;
        std::string password;
        int author_id;
    
    Login(std::string user, std::string password, int author_id);
    public:
    // Funções de edicao do login
    void editUser(std::string user);
    void editPassword(std::string password);
    void editId(int author_id);

    // Metodos que retornam as variaveis de login 
    std:: string getpassword();
    std:: string getuser();
    int getautor_id();



};


