#include<iostream>
#include<string>
#include<unistd.h>
#include "login.h"
#include "admin.h"
#include "employee.h"

using std::cout;
using std::cin;
using std::endl;

extern madness::Employee emp[100];

namespace madness{
    admin::admin():login(){}
    admin::admin(string u,string p):login(u,p){
        cout<<"New Admin with username "<<u<<" is created."<<endl;
    }
    void admin::adm_panel(){
        int choice;
        do{
            if(choice!=4) system("clear");
            cout<<"Welcome back "<<getusername()<<endl;
            cout<<"What do you want to do: "<<endl;
            cout<<"1.Add Employee "<<endl;
            cout<<"2.Remove Employee "<<endl;
            cout<<"3.Edit Employee "<<endl;
            cout<<"4.List all Employee"<<endl;
            cout<<"5.Accepting Promotions"<<endl;
            cout<<"6.Change Your Password"<<endl;
            cout<<"Press 0 for logout admin panel"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                {
                    string user,pass;
                    char c;
                    int s,e;
                    cout<<"Enter New Employee Credentials"<<endl;
                    cout<<"Enter username: ";
                    cin>>user;
                    cout<<"Enter password: ";
                    cin>>pass;
                    cout<<"Enter Salary: ";
                    cin>>s;
                    cout<<"Enter Experience: ";
                    cin>>e;
                    for(int i=0; i<100; i++){
                        if(emp[i].getusername()==""){
                            emp[i]= Employee(user,pass,s,e);
                            cout<<"New Employee is created"<<endl;
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    cout<<"Enter id of Employee to remove: "<<endl;
                    int temp;
                    cin>>temp;
		    emp[temp-2].RemoveEmployee();
                    break;

                }
                case 3:
                {
                    cout<<"Enter Employee id to edit employee.";
                    int temp;
                    cin>>temp;
                    emp[temp-2].EditEmployee();
                    break;
                }
                case 4:
                {
                    cout<<"========================================================"<<endl;
                    for(int i=0; i<100; i++){
                        if(emp[i].getusername()!=""){
                            emp[i].details();
                            cout<<"========================================================"<<endl;
                        }
                    }
                    
                    break;
                }
                case 5:
                {
                    for(int i=0; i<100; i++){
                        if(emp[i].status()=="Hold") emp[i].review();
                    }
                    break;
                }
                case 6:
                {
                    cout<<"Enter new password"<<endl;
                    string passwd;
                    cin>>passwd;
                    setpassword(passwd);
                    break;
                }
                default:
                    return;
            }
        }while(choice!=0);
    }
}
