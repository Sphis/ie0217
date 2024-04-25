#include "libro.hpp"
#include "biblioteca.hpp"

int main() {
    Biblioteca miBiblioteca;
    miBiblioteca.agregarLibro({"Cien años de soledad", "Gabriel García Márquez", 1967});
    miBiblioteca.agregarLibro({"1984", "George Orwell", 1949});
    miBiblioteca.agregarLibro({"El señor de los anillos", "J.R.R. Tolkien", 1954});
    miBiblioteca.agregarLibro({"Dune", "Frank Herbert", 1965});

    miBiblioteca.ordenarLibrosPorAnio();
    miBiblioteca.mostrarLibros();

    auto libro = miBiblioteca.buscarLibroPorTitulo("1984");
    if (libro != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    miBiblioteca.contarLibro("1984");

    miBiblioteca.eliminarLibroPorTitulo("1984"); // Asumiendo que se ingresa el nombre correcto
    miBiblioteca.mostrarLibros();

    return 0;
}
