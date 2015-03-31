#ifndef AUTH_LOGIN_MANAGER_H_
#define AUTH_LOGIN_MANAGER_H_

#include "user.h"
#include "mysql_conn.h"

using namespace utils;

namespace auth {

class LoginManager
{
public:
    LoginManager();
    virtual ~LoginManager();

public:
    string login(const User& user);

private:
    bool auth(const User& user);

    string createSession(const User& user);

    bool getUserByName(User& user);

private:
    MySqlConnPtr mysqlConnPtr_;

};

}

#endif
