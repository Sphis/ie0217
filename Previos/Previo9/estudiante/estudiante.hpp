#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>

class Estudiante {
public:
    // Constructor usado para Estudiante
    Estudiante(const std::string& nombre, int edad);
    void mostrarDatos();

private:
    // Atributos
    std::string nombre;
    int edad;
    int edad2;
};

#endif
