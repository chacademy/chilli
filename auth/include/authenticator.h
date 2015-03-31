#include "user.h"
#include "register.h"
#include "login_manager.h"

#include <string>
#include <iostream>

namespace auth {


class Authenticator
{
public:
Authenticator();

    string getVerifyCode();
    bool registerUser(const User& user);
    string login(const User& user);

private:
    Register register_;
    LoginManager loginManager_;
};

}
