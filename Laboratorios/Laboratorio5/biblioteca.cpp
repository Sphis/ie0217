#include "libro.hpp"
#include "biblioteca.hpp"

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
}

void Biblioteca::mostrarLibros() {
    for (const auto& libro : libros) {
        std::cout << libro.titulo << ", " << libro.autor << ", " << libro.anioPublicacion << std::endl;
    }
}

void Biblioteca::ordenarLibrosPorAnio() {
    std::sort(libros.begin(), libros.end());
}

std::vector<Libro>::iterator Biblioteca::buscarLibroPorTitulo(const std::string& titulo) {
    return std::find_if(libros.begin(), libros.end(), [&titulo](const Libro& l) {
        return l.titulo == titulo;
    });
}

void Biblioteca::eliminarLibroPorTitulo(const std::string& titulo) {
    auto eliminar = std::remove_if(libros.begin(), libros.end(), [&titulo](const Libro& l) {
        return l.titulo == titulo;
    });
    libros.erase(eliminar, libros.end());
    std::cout << "Se ha eliminado el libro " << titulo << std::endl;
}

void Biblioteca::contarLibro(const std::string& titulo) {
    int cantidad = std::count_if(libros.begin(), libros.end(), [&titulo](const Libro& libro) {
        return libro.titulo == titulo;
    });
    std::cout << "La cantidad de libros con el titulo " << titulo << " en la biblioteca es de: " << cantidad << std::endl;
}

std::vector<Libro>::iterator Biblioteca::end() {
    return libros.end();
}