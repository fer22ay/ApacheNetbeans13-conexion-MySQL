#include "Producto.h"
#include <iostream>
#include <string>

using namespace std;

Producto::Producto() {

}

Producto::~Producto() {

}

void Producto::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Producto::getNombre() {
    return this->nombre;
}

void Producto::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

std::string Producto::getDescripcion() {
    return this->descripcion;
}

/**
 * Metodo para asignar el estado del producto 1 = ACTIVO, 0 = INACTIVO
 * @param estado tipo Char
 */
void Producto::setEstado(std::string estado) {
    this->estado = estado;
}

/**
 * Metodo para obtener el estado del producto
 * @return Retorna el estado del producto
 */
std::string Producto::getEstado() {
    return this->estado;
}

/**
 * Metodo para asignar precio al producto
 * @param precio tipo Double
 */
void Producto::setPrecio(std::string precio) {
    this->precio = precio;
}

/**
 * Metodo para obtener el precio del producto
 * @return Precio del producto
 */
std::string Producto::getPrecio() {
    return this->precio;
}