#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

Database::Database() {

}

Database::~Database() {

}

/**
 * Metodo encargado de recibir el nombre de la base de datos que se utilizara para conectar a MySQL
 * @param DBname Representa el nombre del esquema o nombre de la base de datos
 */
void Database::SetDatabase(std::string DBname) {
    try {
        this->conn->setSchema(DBname);
    } catch (sql::SQLException &e) {
        cout << "Error name database: " << e.what() << endl;
    }
}

/**
 * Metodo para conectarse a la base de datos MySQL con las credenciales del usuario
 * @param username Nombre de usuario para la conexion
 * @param password Credenciales para la conexion
 */
void Database::Connect(std::string username, std::string password) {
    try {
        this->driver = get_driver_instance();
        this->conn = this->driver->connect("tcp://127.0.0.1:3306", username, password);
        cout << "Connection...!" << endl;
    } catch (sql::SQLException &e) {
        cout << "Error validate username or password" << e.what() << endl;
    }
}

/**
 * Method to closing connection to database
 */
void Database::Close() {
    try {
        delete this->rest;
        delete this->stmt;
        delete this->conn;
        delete this->pstmt;
    } catch (sql::SQLException &e) {
        cout << "Error closed session" << e.what();
    }
}

void Database::Execute(std::string query) {
    try {
        this->stmt = this->conn->createStatement();
        this->stmt->execute(query);
    } catch (sql::SQLException & e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}

void Database::Execute_Query(std::string query, std::vector<std::string> params) {
    try {
        this->pstmt = this->conn->prepareStatement(query);

        int b = 1;
        for (int a = 0; a < params.size(); a++) {
            if (!params[a].find("S:"))
                this->pstmt->setString(b, params[a].substr(2, params[a].length()));
            else if (!params[a].find("I:"))
                this->pstmt->setInt(b, atoi(params[a].substr(2, params[a].length()).c_str()));
            b++;
        }

        this->pstmt->execute();
    } catch (sql::SQLException & e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}

/**
 * Metodo para listar los datos de la tabla
 * @param query Representa el query para consultar a la base de datos
 */
void Database::Select(std::string query) {
    try {
        this->stmt = this->conn->createStatement();
        this->rest = this->stmt->executeQuery(query);
        while (this->rest->next()) {
            cout << "Codigo de producto es: " << this->rest->getString("codigo") << endl;
            cout << "Nombre producto es: " << this->rest->getString("nombre") << endl;
            cout << "Descripcion del producto: " << this->rest->getString("descripcion") << endl;
            cout << "Estado producto: " << this->rest->getString("estado") << endl;
            cout << "Precio producto: " << this->rest->getString("precio") << endl;
        }
    } catch (sql::SQLException &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}

/**
 * Metodo para insertar productos en la base de datos
 * @param query Representa el query para insertar lso datos en la base de datos
 */
void Database::Insert(std::string query, std::vector<std::string> params) {
    try {

        this->Execute_Query(query, params);

    } catch (sql::SQLException &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}

void Database::Update(std::string query, std::vector<std::string> params) {
    try {
        this->Execute_Query(query, params);
    } catch (sql::SQLException &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}

/**
 * 
 * @param query
 * @param params
 */
void Database::Delete(std::string query, std::vector<std::string> params) {
    try {
        this->Execute_Query(query, params);
        cout << "Producto eliminado con exito";
    } catch (sql::SQLException &e) {
        cout << "Error: " << e.what() << endl;
        cout << "Error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
}