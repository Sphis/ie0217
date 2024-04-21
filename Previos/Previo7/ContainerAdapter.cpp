#include <iostream>
#include <stack>
using namespace std;

// Un adaptador es toman un contenedor existente y proporcionan una interfaz restringida
// Una pila es un contenedor adaptado
int main() {

  // create a stack of ints
  stack<int> numbers;

  // push into stack
  numbers.push(1);
  numbers.push(100);
  numbers.push(10); // Recuerde que una pila es LIFO

  cout << "Numbers are: ";

  // we can access the element by getting the top and popping
  // until the stack is empty
  while(!numbers.empty()) {
    // print top element
    cout << numbers.top() << ", "; // .top() para sacar el elemento

    // pop top element from stack
    numbers.pop(); // .pop() para eliminarlo
  }

  return 0;
}