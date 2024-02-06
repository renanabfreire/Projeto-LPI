#ifndef LOGIN_H
#define LOGIN_H
#include <string>

class Login
{
    public:
    
        std::string user;
        std::string password;
        int author_id;
    
    Login();
    Login(std::string user, std::string password, int author_id);

    // Funções de edicao do login
    bool editUser(std::string user);
    bool editPassword(std::string password);
    bool editId(int author_id);

};

#endif // LOGIN_H
