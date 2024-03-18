#include <iostream>
using namespace std;
int main() {
    float array[3]; // Initialize 3 element array

    // Declare pointer variable
    float *pointer;
    cout << "Displaying address using arrays: " << endl;

    // Using for loop to print addresses of all array elements
    for (int i = 0; i < 3; ++i) {
        cout << "&array[" << i << "] = " << &array[i] << endl;
    }

    // ptr = &array[0]
    pointer = array;
    cout << "\n Displaying address using pointers: " << endl;

    // Use for loop to print addresses of all array elements
    // Using pointer notation
    for (int i = 0; i < 3; ++i) {
        cout << "ptr + " << i << " = " << pointer + i << endl;
    }
    // Notice how even though the code adds 1, 2, 3 to the pointer, it still recognizes 
    // that each element is 4 bits wide e.g. f8 + 4 = fc

    return 0;
}