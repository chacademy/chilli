#include "mysql_conn.h"

#include <iostream>

using namespace std;
using namespace utils;

MySqlConn::MySqlConn(MySqlConnOption connOption)
    :mysql_(NULL),mysql_res_(NULL)
{
    connOption_ = connOption; 
    //mysql_library_init(0, NULL, NULL);
}

MySqlConn::~MySqlConn()
{
    freeResult();
    close();
    mysql_library_end();
}

bool MySqlConn::connect()
{
    mysql_ = mysql_init(mysql_);
    if (mysql_ == NULL)
    {
        return false;
    }

    mysql_ = mysql_real_connect(mysql_, 
                connOption_.host.c_str(),
                connOption_.user.c_str(),
                connOption_.password.c_str(),
                connOption_.db.c_str(),
                0,
                NULL,
                0);

    if (mysql_ == NULL)
    {
        return false;
    }

    return true;
}

bool MySqlConn::query(const string& strSql)
{
    if (0 != mysql_query(mysql_, strSql.c_str()))
    {
        // cerr
        return false;
    }

    return true;
}

bool MySqlConn::queryResult(const string& strSql)
{
    if (!query(strSql))
    {
        cout << "Failed to execute SQL: " << strSql << endl; 
        return false;
    }

    freeResult(); // release mem

    mysql_res_ = mysql_store_result(mysql_);
    if (!mysql_res_)
    {
        cout << "No result returned." << endl;
        return false;
    }

    return true;
}

int MySqlConn::getResultNumRows()
{
    int rowNum = mysql_num_rows(mysql_res_);
    return rowNum;
}

MYSQL_RES* MySqlConn::getMySqlResult()
{
    return mysql_res_;
}
