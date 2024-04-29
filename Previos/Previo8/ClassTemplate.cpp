#include <iostream>
using namespace std;

// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};

int main() {

    // create object with int type
    Number<int> numberInt(7); // Formato es nombreDeClase<DataType> ObjetoClase. En este caso se inicializa la clase con el int "7"

    // create object with double type
    Number<double> numberDouble(7.7); // Ahora T es un double en lugar de int

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    // Note que esto es util porque sin templates hubiera tenido que crear 2 clases
    return 0;
}