#ifndef __login
#define __login

#include<string>

using std::string;

namespace madness{
    class login{
        private:
            int id;
            string username,password;
            static int counter;
        public:
            login();
            login(string,string);
            int getid();
            string getusername();
            string getpassword();
            void setusername(string);
            void setpassword(string);

    };
}

#endif