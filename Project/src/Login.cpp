#include "Login.h"


Login :: Login(std::string user, std::string password, int author_id){

    this-> user =  user;
    this-> password = password;
    this-> author_id = author_id;
}

void Login :: editUser(std::string user){

    this-> user =  user;

}

void Login :: editPassword(std::string password){

    this-> password = password;

}

void Login :: editId(int autor_id){

    this-> author_id = author_id;
}

std:: string Login:: getuser(){

    return user;

}

std:: string Login:: getpassword(){

    return password;

}

int Login:: getautor_id(){

    return author_id;

}