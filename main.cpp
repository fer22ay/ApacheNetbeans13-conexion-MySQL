/* 
 * File:   main.cpp
 * Author: fernando
 *
 * Created on June 9, 2022, 11:22 AM
 */
#include "Database.h"
#include "Producto.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include <stdlib.h>


using namespace std;

void showMenu();
void listarProductos();

static Database *db = new Database();

int main(int argc, char** argv) {

    db->Connect("root", "mysql");
    db->SetDatabase("test");

    showMenu();

    return 0;
}

void listarProductos() {
    db->Select("SELECT codigo, nombre, descripcion, estado, precio FROM productos WHERE estado = 'A'");
    db->Close();
}

void insertarProducto() {
    Producto *producto = new Producto();

    std::string nombre;
    std::string descripcion;
    std::string estado;
    std::string precio;

    cout << "Debe ingresar los siguientes datos" << endl;
    cout << "Nombre producto: ";
    getline(cin, nombre);
    if (nombre.empty()) {
        cout << "Nombre no debe estar vacio, ingrese de nuevo el nombre: " << endl;
        getline(cin, nombre);
    }
    producto->setNombre(nombre);
    cout << "Descripcion producto: ";
    getline(cin, descripcion);
    producto->setDescripcion(descripcion);
    cout << "Estado A = Activo o I = Inactivo: ";
    cin >> estado;
    producto->setEstado(estado);
    cout << "Precio producto: ";
    cin >> precio;
    producto->setPrecio(precio);

    db->Insert("INSERT INTO productos(nombre, descripcion, estado, precio) VALUES(?,?,?,?)",{"S:" + producto->getNombre(), "S:" + producto->getDescripcion(), "S:" + producto->getEstado(), "I:" + producto->getPrecio()});

    cout << "Datos insertados " << producto->getNombre() << " Precio: " + producto->getPrecio() << endl;
    db->Close();

}

void actualizarProducto() {

    Producto *producto = new Producto();
    int codigoProducto;
    std::string nombre;

    cout << "Actualizar datos de producto, debe ingresar un codigo para realizar proceso" << endl;
    cout << "Ingrese codigo a actualizar datos: ";
    cin >> codigoProducto;
    cout << "Ingrese nombre:";
    cin >> nombre;
    producto->setNombre(nombre);

    db->Update("UPDATE productos SET nombre=? WHERE codigo=?",{"S:" + producto->getNombre(), "I:" + to_string(codigoProducto)});
    db->Close();

    cout << producto->getNombre() << " Codigo: " << codigoProducto;

}

void eliminarProducto() {

    int codigoProducto;
    
    cout << "Debe ingresar un codigo de producto existente para eliminar" << endl;
    cout << "Ingrese codigo: ";
    cin >> codigoProducto;
    
    db->Delete("DELETE FROM productos WHERE codigo=?", {"I:" + to_string(codigoProducto)});
    db->Close();
    
}

void showMenu() {
    int exit = 0;
    do {

        cout << endl;
        cout << "BIENVENIDO SELECIONA UNA OPCION" << endl;
        cout << endl;
        cout << "1. Listar productos" << endl;
        cout << "2. Crear producto" << endl;
        cout << "3. Actualizar producto" << endl;
        cout << "4. Eliminar producto" << endl;

        int response;
        cout << endl;
        cout << "Ingresa una opcion: ";
        cin >> response;
        cout << endl;

        switch (response) {

            case 0:
                exit = 0;
                break;
            case 1:
                listarProductos();
                break;
            case 2:
                insertarProducto();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            default:
                system("clear");
                exit = 0;
                break;

        }

    } while (exit != 0);
}

