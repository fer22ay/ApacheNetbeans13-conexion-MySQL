/* 
 * File:   Database.h
 * Author: fernando
 *
 * Created on June 9, 2022, 11:58 AM
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <iostream>
#include <cstdlib>

#include <stdlib.h>

#include <mysql-cppconn-8/jdbc/mysql_driver.h>
#include <mysql-cppconn-8/jdbc/mysql_connection.h>
#include <mysql-cppconn-8/jdbc/cppconn/driver.h>
#include <mysql-cppconn-8/jdbc/cppconn/exception.h>
#include <mysql-cppconn-8/jdbc/cppconn/resultset.h>
#include <mysql-cppconn-8/jdbc/cppconn/statement.h>
#include <mysql-cppconn-8/jdbc/cppconn/resultset_metadata.h>
#include <mysql-cppconn-8/jdbc/cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

struct Database {
protected:
    sql::Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *rest;
    sql::PreparedStatement *pstmt;

private:
    void Execute_Query(std::string, std::vector<std::string>);

public:
    Database();
    ~Database();
    Database(std::string, std::string, std::string, std::string);
    void Execute(std::string);
    void Close();
    void SetDatabase(std::string);
    void Connect(std::string, std::string);
    void Insert(std::string, std::vector<std::string>);
    void Update(std::string, std::vector<std::string>);
    void Delete(std::string, std::vector<std::string>);
    void Select(std::string);
    
    void ActualiarProducto(std::string);

    std::vector<std::vector<std::string>>
    Execute(std::string, int);

};

#endif /* DATABASE_H */

