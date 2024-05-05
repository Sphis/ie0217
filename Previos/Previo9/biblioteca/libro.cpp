#include <iostream>
#include "libro.hpp"

// Implementacion del constructor
Libro::Libro(
    const std::string& titulo, const std::string& autor
): titulo(titulo), autor (autor) {}

// Implementacion del metodo
void Libro::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl;
}
