#ifndef __admin
#define __admin

#include "login.h"
namespace madness{
    class admin: public login{
        private:

        public:
            admin();
            admin(string,string);
            void adm_panel();
    };
}
#endif