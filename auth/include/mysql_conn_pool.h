#ifndef UTILS_MYSQL_CONN_POOL_H_
#define UTILS_MYSQL_CONN_POOL_H_

#include <string>
#include <tr1/memory>

#include "mysql_conn.h"

using namespace std;

namespace utils {

class MySqlConnPool;

typedef tr1::shared_ptr<MySqlConnPool> MySqlConnPoolPtr;

class MySqlConnPool 
{
protected:
    MySqlConnPool();

public:
    virtual ~MySqlConnPool();

public:
    static MySqlConnPoolPtr getInstance();

    bool initDefault();
    MySqlConnPtr getSingleConn();
    
private:
    static MySqlConnPoolPtr mysqlConnPoolPtr_;

    MySqlConnPtr mysqlConnPtr_;


};

}

#endif

