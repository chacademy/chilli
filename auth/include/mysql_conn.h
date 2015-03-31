#ifndef UTILS_MYSQL_CONN_
#define UTILS_MYSQL_CONN_

#include <string>
#include <tr1/memory>

#include <mysql/mysql.h>

using namespace std;

namespace utils {

class MySqlConn;

typedef std::tr1::shared_ptr<MySqlConn> MySqlConnPtr;

class MySqlConn
{
public:
    class MySqlConnOption
    {
    public:
        string host;
        string db;
        string user;
        string password;
        string charset;
    };

    MySqlConn(MySqlConnOption connOption);

    virtual ~MySqlConn(); 

    bool connect();

    bool query(const string& strSql);
    bool queryResult(const string& strSql);

    int getResultNumRows();

    MYSQL_RES* getMySqlResult();

private:
    void freeResult() 
    {
        if (mysql_res_)
        {
            mysql_free_result(mysql_res_);
            mysql_res_ = NULL;
        }
    }

    void close()
    {
        if (mysql_)
        {
            mysql_close(mysql_);
            mysql_ = NULL;
        }
    }

private:
    MySqlConnOption connOption_;
    
    MYSQL* mysql_;
    MYSQL_RES* mysql_res_;

};

}

#endif

