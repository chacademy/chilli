#include "authenticator.h"
#include "verifycode.h"

#include <sstream>
#include <string>

using namespace std;
using namespace utils;

namespace auth {

Authenticator::Authenticator()
{
}

string Authenticator::getVerifyCode()
{
    return register_.getVerifyCode();
}

bool Authenticator::registerUser(const User& user)
{
    return register_.registerUser(user);
}

string Authenticator::login(const User& user)
{
    cout << "login User: " << user.name << endl;
    return loginManager_.login(user);
}

}
