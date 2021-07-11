#include<iostream>
#include<string>
#include "login.h"

using std::cout;
using std::string;
namespace madness{
    int login::counter=1;
    login::login(){}
    login::login(string u, string p){
        this->username = u;
        this->password = p;
        id = counter++;
    }
    int login::getid(){
        return id;
    }
    string login::getusername(){
        return username;
    }
    string login::getpassword(){
        return password;
    }
    void login::setusername(string u){
        username = u;
    }
    void login::setpassword(string p){
        password = p;
    }
}