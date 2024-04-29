#include <iostream>
using namespace std;

// Variable T va a ser definido cuando se llama la funcion
// T se puede ver como un datos variable (que puede ser int, double, etc.)
template <typename T>
T add(T num1, T num2) {
   return (num1 + num2); // Devolver la suma
}

int main() {

    int result1;
    double result2;
    // calling with int parameters
    result1 = add<int>(2, 3); // Le decimos al compilador que le estoy pasando int
    cout << result1 << endl;

    // calling with double parameters
    result2 = add<double>(2.2, 3.3); // Le decimos al compilador que le estoy pasando double
    cout << result2 << endl;

    return 0;
}    