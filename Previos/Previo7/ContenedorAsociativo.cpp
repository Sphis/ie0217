#include <iostream>
#include <set>
using namespace std;

int main() {

  // initialize a set of int type
  set<int> numbers = {1, 100, 10, 70, 100};

  // print the set
  // Un set no permite datos repetidos entre sus elementos, por eso no se muestra 100 dos veces
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}