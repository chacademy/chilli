#ifndef AUTH_REGISTER_H_
#define AUTH_REGISTER_H_

#include "user.h"
#include "mysql_conn.h"

using namespace utils;

namespace auth {

class Register
{
public:
    Register();
    virtual ~Register();

public:
   string getVerifyCode();

   bool registerUser(const User& user);

private:
   bool isUserRegistered(const User& user);

   bool registerAnUser(const User& user);


private:
    MySqlConnPtr mysqlConnPtr_;
};

}

#endif

