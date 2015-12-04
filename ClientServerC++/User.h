//
// Created by alejandrofrech on 11-27-15.
//
#ifndef CLIENTSERVERC_USER_H
#define CLIENTSERVERC_USER_H
#include <string>
using namespace std;


class User {
    string Username;
    string Name;
    string Email;
    string Cedula;
    string Date;
    string ImgUrl;

public:
    User(string username,string name,string email,string cedula, string date,string img ){
        this->Username=username;
        this->Name=name;
        this->Email=email;
        this->Cedula=cedula;
        this->Date=date;
        this->ImgUrl=img;
    }

    string to_s();

};


#endif //CLIENTSERVERC_USER_H
