#include <iostream>
using namespace std;

// Por estandar, se acostumbra a usar defines en mayuscula, aqui se define una constante
#define MI_PRIMER_DEFINE 925

// Un "enum" es un tipo de dato definido por el usuario que consiste en un conjunto de
// enteros (int) asociado con un nombre. 
enum seasons {
    spring = 34,
    summer = 4,
    autumn = 9,
    winter = 32
}; // Note que hay que terminar el enum con ;

// Si tengo carro = 40, el resultado de abajo seria arbol = 42
enum enumcito {
    carro, // Indice  0,    40
    casa,          // 1,    41
    arbol,         // 2,    42
    patio          // 3,    43
};

int main() {
    ////// Ejemplo 2, 37:23
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl;
    // En este caso se imprime el valor 4 porque esta asociado s = summer = 4.
    // Inclusive, si hago s = 34 que es un valor reconocido (winter) me genera error.
    // Util para tener valores relacionados predeterminados.

    ////// Ejemplo 3, 43:42
    cout << "Define = " << MI_PRIMER_DEFINE << endl;

    cout << "arbol = " << arbol << endl;

    return 0;
}