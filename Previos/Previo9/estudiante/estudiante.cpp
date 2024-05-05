#include <iostream>
#include "estudiante.hpp"

// Definicion del constructor
Estudiante::Estudiante(
    const std::string& nombre, int edad
): nombre (nombre), edad (edad) {}

// Definicion del metodo
void Estudiante::mostrarDatos () {
    std::cout << "Nombre: " << nombre;
    std::cout << ", Edad: " << edad << std::endl;
}