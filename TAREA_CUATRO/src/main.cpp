#include "matriz.h"
#include <iostream>

using namespace std;

// Enumeraciones para las opciones del menu
enum opciones {
    DATOSALEATORIOS = 1,
    MOSTRAR_MATRICES,
    OPERACION,
    SALIR
};

int main() {
    int opcion, datos;
    int filasA, columnasA, filasB, columnasB;
    string operacion;

    cout << "Ingrese el numero de filas de la matriz A: ";
    cin >> filasA;
    cout << "Ingrese el numero de columnas de la matriz A: ";
    cin >> columnasA;

    cout << "Ingrese el numero de filas de la matriz B: ";
    cin >> filasB;
    cout << "Ingrese el numero de columnas de la matriz B: ";
    cin >> columnasB;


    Matriz matrizA(filasA, columnasA, 0.0);
    matrizA.setDimensiones(filasA, columnasA);
    matrizA.llenarMatriz();
    matrizA.print();

    Matriz matrizB(filasB, columnasB, 0.0);
    matrizB.setDimensiones(filasA, columnasA);
    matrizB.llenarMatriz();
    matrizB.print();

    Matriz matrizC = matrizA + matrizB;
    matrizC.print();

    cout << "Ingrese el tipo de operacion: (Suma, Resta o Multiplicacion)";
    cin >> operacion;

    do {
        cout << "Selecciona su opcion: " << endl;
        cout << "1. Generar datos aleatorios: " << endl;
        cout << "2. Mostrar matrices ingresadas" << endl;
        cout << "3. Ejecutar operacion" << endl;
        cout << "4. Finalizar" << endl;
        cin >> opcion;

        switch (opcion) {
            case DATOSALEATORIOS:
                
                break;
            case MOSTRAR_MATRICES:
            
                break;
            case OPERACION:
            
                break;
            case SALIR:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no permitida." << endl;
                break;
        }
    } while (opcion != SALIR);

    return 0;
}