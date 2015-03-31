#include "mysql_conn_pool.h"

#include <iostream>

using namespace std;

namespace utils {


MySqlConnPoolPtr MySqlConnPool::mysqlConnPoolPtr_;

MySqlConnPool::MySqlConnPool()
{

}


MySqlConnPool::~MySqlConnPool()
{

}

MySqlConnPoolPtr MySqlConnPool::getInstance()
{
    if (!mysqlConnPoolPtr_.get())
    {
        cout << "Init MysqlConnPool!" << endl;
        mysqlConnPoolPtr_.reset(new MySqlConnPool);
    }

    return mysqlConnPoolPtr_;
}

bool MySqlConnPool::initDefault()
{
    MySqlConn::MySqlConnOption connOption;
    connOption.host = "localhost";
    connOption.user = "root";
    connOption.password =  "root123";
    connOption.db = "auth_db";
    connOption.charset = "UTF8";
    
    mysqlConnPtr_.reset(new MySqlConn(connOption));

    bool ret = mysqlConnPtr_->connect();
    if (ret)
    {
        cout << "MySql connected!" << endl;
    }
    else 
    {
        cout << "Failed to connect to MySql" << endl;
    }

    return ret;
}

MySqlConnPtr MySqlConnPool::getSingleConn()
{
    return mysqlConnPtr_;
}

}
