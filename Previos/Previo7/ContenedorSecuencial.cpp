#include <iostream>
#include <vector>
using namespace std;

int main() {

  // initialize a vector of int type
  vector<int> numbers = {1, 100, 10, 70, 100};

  // print the vector
  // Es de forma secuencial, por eso se imprime en el mismo orden
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}