#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>

class Libro {
    public:
        std::string titulo;
        std::string autor;
        int anioPublicacion;

        Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}

        // Creando operador que permite se puedan hacer comparaciones de objetos libro
        bool operator<(const Libro& l) const {
            return anioPublicacion < l.anioPublicacion;
        }
};

#endif
