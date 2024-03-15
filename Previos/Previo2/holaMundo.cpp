#include <iostream> // Paquete usado para controlar entradas y salidas

// Ejemplo 1 empezando en 28:04
int ejemplo1() {
    std::cout << "Hola mundo, estudiantes de IE0217!\n";

    // Declaracion de variables
    int var1 = 0;
    int var2;

    var2 = (var1 == 0) ? 15 : 27; // Ejemplo de operador ternario

    std::cout << "var2: \n" << var2 << "";

    return 0;
}

// Ejemplo 2 empezando en 41:17
int ejemplo2() {
    int var1 = 1;
    int var2 = 2;
    int var3 = 3;

    // En este caso se va a ejecutar el case 1 porque el valor de la condición
    // del case (1) coincide con el valor de var1
    switch (var1) {
    case 1:
        std::cout << "Case 1\n";
        break;
    case 2:
        std::cout << "Case 2\n";
        break;
    case 3:
        std::cout << "Case 3\n";
        break;

    default:
        std::cout << "Case default\n";
        break;
    }
}

int main(int argc, char* argv[]) {
    ejemplo1(); // Ejecutar primer ejemplo
    ejemplo2(); // Ejecutar el segundo ejemplo

    ///////////////////// Ejemplo 3 empezando en 1:06:06 /////////////////////
    // argc es el contador de argumentos y argv[] es el vector de argumentos
    // aqui se imprimen dichos parámetros que se le pasan como argumento
    std::cout << "argc: " << argc << std::endl;
    std::cout << "argv[0]: " << argv[0] << std::endl;
    std::cout << "argv[1]: " << argv[1] << std::endl;
    std::cout << "argv[2]: " << argv[2] << std::endl;
    std::cout << "argv[3]: " << argv[3] << std::endl;

    return 0;
}