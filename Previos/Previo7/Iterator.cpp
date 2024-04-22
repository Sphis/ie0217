#include <iostream>
#include<vector>
using namespace std;

// Es importante saber que los iteradores tienen que ser del mismo tipo que el contenedor.

// vector<string>::iterator itr = languages.begin();
// es equivalente a: auto itr = languages.begin();

int main() {

    vector <string> languages = {"Python", "C++", "Java"};

    // create an iterator to a string vector
    vector<string>::iterator itr;

    // iterate over all elements
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", "; // *itr = "es igual al contenido de"
    }

    return 0;
}