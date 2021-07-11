#ifndef __employee
#define __employee
#include<string>
#include "login.h"
using std::string;
namespace madness{
    class Employee:public login{
        private:
            int salary,experience;
            string state;
        public:
            Employee();
            Employee(string,string,int,int);
            void RemoveEmployee();
            void emp_panel();
            void EditEmployee();
            string status();
            void apply();
            void details();
            void review();
    };
}

#endif