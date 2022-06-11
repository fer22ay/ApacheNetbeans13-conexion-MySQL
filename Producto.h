/* 
 * File:   Producto.h
 * Author: fernando
 *
 * Created on June 9, 2022, 1:10 PM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <cstdlib>

#include <stdlib.h>

using namespace std;

struct Producto {
private:
    std::string nombre;
    std::string descripcion;
    std::string estado;
    std::string precio;

public:
    Producto();
    ~Producto();

    void setNombre(std::string);
    std::string getNombre();
    void setDescripcion(std::string);
    std::string getDescripcion();
    void setEstado(std::string);
    std::string getEstado();
    void setPrecio(std::string);
    std::string getPrecio();

};

#endif /* PRODUCTO_H */

