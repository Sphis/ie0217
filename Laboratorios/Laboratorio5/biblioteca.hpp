#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "libro.hpp"

class Biblioteca {
    private:
        std::vector<Libro> libros;

    public:
        // Esta funcion se encarga de agregar libros, se usa pushback() que es usado para agregar un elemento al final de un vector
        void agregarLibro(const Libro& libro);
        // Funcion usada para iterar sobre los libros e imprimir sus datos (titulo, autor y año de publicacion)
        void mostrarLibros();
        // Ordenar los libros de forma ascendiente
        void ordenarLibrosPorAnio();
        // Funcion que crea un iterador de tipo libro que busca de principio a fin los titulos que hay en la biblioteca y devuelve si encontro ese libro o no
        std::vector<Libro>::iterator buscarLibroPorTitulo(const std::string& titulo);
        // Funcion que devuelve el libro
        std::vector<Libro>::iterator end();
        // En esta funcion se ingresa el nombre de alguno de los libros y se borra utilizando remove_if
        void eliminarLibroPorTitulo(const std::string& titulo);
        // Funcion que cuenta la cantidad de libros de un titulo en especifico
        void contarLibro(const std::string& titulo);
};

#endif