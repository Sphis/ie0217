#include <iostream>
using namespace std;

// Class template with multiple and default parameters
template <class T, class U, class V = char> // Esto quiere decir que voy a recibir 3 datos, pero el tercero es opcional y si no es incluido
// se toma como un char
class ClassTemplate {
   private:
   // Definicion de variables
    T var1;
    U var2;
    V var3;

   public:
   // Inicializar la clase con v1, v2 y v3
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}  // constructor, inicializa el var1 con el valor de v1...

    void printVar() {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }
};

int main() {
    // create object with int, double and char types
    ClassTemplate<int, double> obj1(7, 7.7, 'c'); // Note que no le estoy pasando el tipo de V, por defecto se toma como char
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // create object with int, double and bool types
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false); // Note que el orden es diferente a la clase anterior, pero no esta mal
    // porque es un template, ademas si le estoy pasando el tipo de V, por lo que aqui es un booleano
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    return 0;
}