#include "biblioteca.hpp"

int main() {
    Biblioteca biblioteca;

    // Se agregan 2 libros pasando sus titulos y autores
    biblioteca.agregarLibro ("El Gran Gatsby", "F. Scott Fitzgerald");
    biblioteca.agregarLibro ("1984", "George Orwell");

    // Mostrar libros agregados
    biblioteca.mostrarCatalogo ();
    
    return 0;
}
