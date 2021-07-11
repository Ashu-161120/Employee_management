#include<iostream>
#include<string>
#include "login.h"
#include "employee.h"
#include "admin.h"

using namespace std;
using madness::login;
using madness::admin;
using madness::Employee;

admin adm[2];
Employee emp[100];
int count=0;
string cookie="";

void banner(){   //Banner of Project
    cout<<"========================================================"<<endl;
    cout<<"\t\tEmployeee Management"<<endl;
    cout<<"========================================================"<<endl;
}

int main(){
    while(true){
        int signupOption;
        string u,p;
        banner();
        cout<<"What do you wanna do?"<<endl;
        cout<<"1.login\n2.Register\nAny other key for exit\n";
        cin>>signupOption;
        if(signupOption==1){
            system("clear");
            banner();
            cout<<"login panel:"<<endl;                  // Login Panel
            cout<<"1.Admin Login\n2.Employee Login\n";
            cin>>signupOption;
            cout<<"Enter Your Username: ";              //username
            cin>>u;
            cout<<"Enter Your Password: ";              //password
            cin>>p;
            system("clear");
            switch(signupOption){
                case 1:                                 //admin login
                    for(int i=0; i<2; i++){
                        if(adm[i].getusername()==u && adm[i].getpassword()==p){
                
                            cookie="admin";
                            adm[i].adm_panel();
                        }
                    }
                    if(cookie!="admin"){
                        system("clear");
                        cout<<"username or password is incorrect."<<endl;
                    }
                    break;
                case 2:                                //employee login
                    if(count!=0){
                            for(int i=0; i<100; i++){
                                if(emp[i].getusername()==u && emp[i].getpassword()==p){
                                    cout<<"Welcome back "<<u<<endl;
                                    cookie = "employee";
                                    emp[i].emp_panel();
                                }
                        }    
                    }
                    else{
                        cout<<"There is no Admin yet so there can't be any Employee\n";
                    }
                    if(cookie!="employee")cout<<"username or password is incorrect."<<endl;
                    break;
            }
        }
        else if(signupOption==2 && count<2){            // register account for admin
            system("clear");
            banner();
            cout<<"You can only register for Admin."<<endl;
            cout<<"Enter Your Username: ";
            cin>>u;
            cout<<"Enter Your Password: ";
            cin>>p;
            system("clear");
            adm[count]= admin(u,p);
            count++;
        }
        else if(signupOption==2){                       //msg if admin is more than required
            cout<<"There is already excedeed limit of Admin.\n";
        }
        else{
            return 0;
        }
    }
}