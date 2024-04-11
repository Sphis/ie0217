#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    string genero;
    Libro* siguiente; // Puntero que devuelve el siguiente libro. Este puntero almacena la direccion de la estructura
};

void agregarLibro(Libro*& lista);
void mostrarLibros(Libro* lista);
void liberarMemoria(Libro*& lista);

#endif