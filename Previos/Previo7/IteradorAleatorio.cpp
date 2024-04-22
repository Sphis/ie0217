#include <iostream>
#include <vector>
using namespace std;

int main() {

    // create a vector
    vector<int> vec{1, 2, 3, 4}; // vector a usar

    // create iterators to point to the first and the last elements 
    vector<int>::iterator itr_first = vec.begin(); // puntero de inicio
    vector<int>::iterator itr_last = vec.end() - 1; // .end() - 1 porque esta funcion apunta al elemento despues del ultimo

    // display the vector elements
    cout << "First Element: " << *itr_first << endl;
    cout << "Second Element: " << itr_first[1] << endl;

    // note que lo que se imprime son dereferencias
    cout << "Second Last Element: " << *(itr_last - 1) << endl; // esto seria el elemento 2
    cout << "Last Element: " << *(itr_last) << endl; // ultimo elemento

    return 0;
}