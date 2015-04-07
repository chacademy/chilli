#include "register.h"
#include "verifycode.h"
#include "mysql_conn_pool.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace utils;

namespace auth {

Register::Register()
{
    MySqlConnPoolPtr mysqlConnPoolPtr = MySqlConnPool::getInstance();
    if (mysqlConnPoolPtr.get())
    {
        mysqlConnPtr_ = mysqlConnPoolPtr->getSingleConn();
    }
    else 
    {
        cout << "Register: Failed to get mysql connection pool!" << endl;
    }
}

Register::~Register()
{
}

string Register::getVerifyCode() 
{

    return utils::VerifyCode::generate(6);
}

bool Register::registerUser(const User& user)
{
    if (isUserRegistered(user))
    {
        cout << "User has aleady been registered!" << endl;
        return false;
    }

    return registerAnUser(user);
}

// private

bool Register::isUserRegistered(const User& user)
{
    ostringstream oss;
    oss << "select 1 from UserInfo where name='" << user.name << "' limit 1" << endl;

    string sql = oss.str();
    cout << sql << endl;

    bool ret = mysqlConnPtr_->queryResult(sql);
    if (ret) 
    {
        if (mysqlConnPtr_->getResultNumRows() > 0) 
        {
            return true;
        }
    }
    else
    {
        cout << "Failed to check user registration (mysql)!" << endl;
    }

    return false;
}

bool Register::registerAnUser(const User& user)
{
    cout << "register User:" << user.name <<endl;
    
    ostringstream oss;
    oss << "insert into UserInfo (name,password,sex) values ('"
        << user.name << "','" << user.password << "'," << user.sex << ")";
    
    string sql = oss.str();

    cout << sql << endl;
    bool ret = mysqlConnPtr_->query(sql);
    if (ret)
    {
        cout << "save to DB success" << endl;
    }
    else
    {
        cout << "save to DB failed!" << endl;
    }

    return ret;
}

}
