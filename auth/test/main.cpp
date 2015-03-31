#include <iostream>

#include <string>
#include <tr1/memory>

#include "authenticator.h"
#include "mysql_conn_pool.h"

using namespace std;
using namespace auth;
using namespace utils;

void testAuth()
{
    MySqlConnPoolPtr mysqlConnPoolPtr = MySqlConnPool::getInstance();
    if (!mysqlConnPoolPtr.get())
    {
        cout << "Failed to get Mysql connetion pool!" << endl;
        return;
    }
    mysqlConnPoolPtr->initDefault();

    Authenticator auth;
/*
    string code;
    int i = 0;
    for ( ; ; i++)
    {
        string code1 = auth.getVerifyCode();
        if (code == code1) {
            continue;
        }
        code = code1;
        cout << code << " " << i << endl;
    }

    cout << code << " " << i << endl;
    */

    // verify code
    string code = auth.getVerifyCode();

    // register
    User user;
    user.name = "abc";
    user.password = "xxxxxxxxx";
    auth.registerUser(user);

    // login
    auth.login(user);

    user.password = "aaaa";
    auth.login(user);
}

int main(int argc, char** argv)
{
    testAuth();
    return 0;
}
