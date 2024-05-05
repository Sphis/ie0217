#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "libro.hpp"

class Biblioteca {
    public:
      void agregarLibro(
        const std::string& titulo,
        const std::string& autor
    );
    void mostrarCatalogo();

private:
    // Vector que almacena los libros que hay
    std::vector<Libro> catalogo;
};

#endif
