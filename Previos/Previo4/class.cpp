#include <iostream>
using namespace std;

    class Molde {
    public:
        double largo;
        double ancho;
        double altura;

        // Constructor de la clase. Funcion que se ejecuta cuando se instancia esta clase

        // Hay 2 forma de hacer el constructor
    ////// Forma 1 (elegante)
        Molde(double largo_p, double ancho_p, double altura_p) : largo(largo_p), ancho(ancho_p), altura(altura_p) {}

    ////// Forma 2
        // Molde(){
        //     cout<<"Esto se ejecuta en cada instanciacion" << endl;
        //     cout << "Iniciando un objeto de la clase Room" << endl;
        // }

    // Decontructor, usado para "cerrar", cuando ya la variable no se usa dentro del scope o ya no es válida
        ~Molde() {
            cout << "Saludos desde el descontructor de la clase Molde." << endl;
        }

        double calcularArea() {
            return largo * ancho;
        }

        double calcularVolumen () {
            return largo * ancho * altura;
        }
    };

int main() {
//// **** Primer metodo, aqui se le pasan los valores similar a una funcion. **** ////
    Molde pared(10, 10, 2);
    /* Calcular y desplegar el area y volumen. */
    cout << "Area = "<< pared.calcularArea() << endl;
    cout << "Volumen = " << pared.calcularVolumen() << endl;

//// **** SEGUNDO METODO (para que funcione ocupa comentar metodo 1 y descomentar metodo 2). **** ////
    /* Instanciar un objeto llamado pared basado en la clase Molde. */
    // Molde pared;

    // /* Asignar valores al objeto pared. SEGUNDO METODO, se le pasan valores directamente*/
    // pared.largo = 5;
    // pared.ancho = 5;
    // pared.altura = 2;

    // /* Calcular y desplegar el area y volumen. */
    // cout << "Area = "<< pared.calcularArea() << endl;
    // cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;
}
