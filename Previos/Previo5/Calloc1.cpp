#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int *ptr; // Puntero de tipo entero
    ptr = (int *) calloc(5, sizeof(int)); // Casting a int porque calloc siempre devuelve void
    if (!ptr) {
        cout << "Memory Allocation Failed";
        exit(1);
    }

    cout << "Initializing values..." << endl << endl;

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1; // 1, 3, 5 ...
    }

    cout << "Initialized values" << endl;
    for (int i = 0; i < 5; i++) {
        /* ptr[i] and *(ptr+i) can be used interchangeably */
        cout << *(ptr + i) << endl;
    }
    free(ptr);
    return 0;
}