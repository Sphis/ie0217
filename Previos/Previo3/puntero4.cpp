#include <iostream>
using namespace std;
int main() {
    int var = 2050;
    int* ptr_var; // Initializing first pointer

    ptr_var = &var; // Storing memory position in pointer

    cout << "var: " << var << ", ptr_var (first pointer): " << ptr_var << endl;

    int** ptr_ptr_var; // Creating second pointer
    ptr_ptr_var = &ptr_var; // Saving the memory adress of the first pointer in second pointer
    cout << "ptr_ptr_var (second pointer): " << ptr_ptr_var << endl;

    return 0;
}