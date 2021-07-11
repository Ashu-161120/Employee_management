#include<iostream>
#include<string>
#include "employee.h"
#include "login.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace madness{
    Employee::Employee():login(){}
    Employee::Employee(string u, string p, int s, int e):login(u,p){
        this->salary = s;
        this->experience = e;
    }
    void Employee::RemoveEmployee(){
        string user="";
        setusername(user);
        setpassword(user);
        salary=0;
        experience=0;


    }
    void Employee::emp_panel(){
        cout<<"What do You want to do: "<<endl;
        cout<<"1.View your details"<<endl;
        cout<<"2.Edit Your Information"<<endl;
        cout<<"3.Apply for promotion"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                details();
                break;
            case 2: 
                EditEmployee();
                break;
            case 3:
                apply();
        }
    }
    void Employee::EditEmployee(){
        cout<<"What do You want to do edit."<<endl;
        cout<<"1. If you want to edit username"<<endl;
        cout<<"2. If you want to change password"<<endl;
        cout<<"3. If you want to change Experience"<<endl;
        int echoice;
        cin>>echoice;
        switch(echoice){
            case 1:
            {
                cout<<"Your current username is ("<<getusername()<<"). \nEnter another username to change";
                string usrname;
                cin>>usrname;
                setusername(usrname);
                break;   
            }
            case 2:
            {
                cout<<"Enter new password: ";
                string passwd;
                cin>>passwd;
                setpassword(passwd);
                break;
            }
            case 3: 
            {
                cout<<"Your experience is "<<experience<<endl;
                cout<<"Enter your current experience: ";
                cin>>experience;
                break;
            }
        }
    }
    string Employee::status(){
        return state;
    }
    void Employee::apply(){
        cout<<"You have applied for promotion(admin will review your request.)"<<endl;
        state = "Hold";
    }
    void Employee::details(){
        cout<<"Name: "<<getusername()<<endl;
        cout<<"Id: "<<getid()<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Experience: "<<experience<<endl;
        cout<<"Promotion Status: "<<status()<<endl;
    }
    void Employee::review(){
        cout<<"Do you want to accept promotion (Successfull or Declined)"<<endl;
        string temp;
        cin>>temp;
        if(temp=="Successfull" || temp=="Declined") state = temp;
        else cout<<"wrong input";
    }
}