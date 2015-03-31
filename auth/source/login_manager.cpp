#include "login_manager.h"
#include "mysql_conn_pool.h"

#include <mysql/mysql.h>

#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace utils;

namespace auth {

LoginManager::LoginManager()
{
    MySqlConnPoolPtr mysqlConnPoolPtr = MySqlConnPool::getInstance();
    if (mysqlConnPoolPtr.get())
    {
        mysqlConnPtr_ = mysqlConnPoolPtr->getSingleConn();
    }
    else 
    {
        cout << "LoginManger: Failed to get mysql connection pool!" << endl;
    }

}

LoginManager::~LoginManager()
{
}

string LoginManager::login(const User& user)
{
    if (auth(user))
    {
        return createSession(user);
    }

    return "";
}

// private

bool LoginManager::auth(const User& user)
{
    // check DB
    User dbUser;
    dbUser.name = user.name;
    getUserByName(dbUser);

    if (user.password == dbUser.password)
    {
        cout << "password matched!" << endl;
        return true;
    }
    else
    {
        cout << "password not match!" << endl;
        return false;
    }

}

string LoginManager::createSession(const User& user)
{
    // TODO
    // generate sessionID : Hash, UUID
    return "sessionID";
}

bool LoginManager::getUserByName(User& user)
{
    ostringstream oss;
    oss << "select ID,password from UserInfo where name='" << user.name <<"' limit 1";

    string sql = oss.str();
    cout << sql << endl;

    bool ret = mysqlConnPtr_->queryResult(sql);
    if (!ret)
    {
        cout << "Failed to check user";
        return false;
    }

    // TODO: Iterator
    MYSQL_RES* mysqlRes = mysqlConnPtr_->getMySqlResult();
    MYSQL_ROW mysqlRow = mysql_fetch_row(mysqlRes);
    while (mysqlRow) {
        user.id = atoi(mysqlRow[0]);
        user.password = mysqlRow[1];
        // only 1 row
        mysqlRow = mysql_fetch_row(mysqlRes);
    }

    return ret;
}

}
