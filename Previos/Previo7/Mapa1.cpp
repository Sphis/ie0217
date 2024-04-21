#include <iostream>
#include <map>
using namespace std;

int main() {
    // map<tipo de dato para el key, tipo de dato para el value> nombre del map
    map<int, string> student;
  
    // use [] operator to add elements
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // use insert() method to add elements
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake")); // Note que los values pueden ser iguales, pero
    // los keys deben ser UNICOS

    // add elements with duplicate keys
    student[5] = "Timothy";
    student[5] = "Aaron"; // Como usan la misma llave el valor se reemplaza, es decir, se pierde Timothy

    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0;
}