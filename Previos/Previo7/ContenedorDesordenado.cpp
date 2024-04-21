#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

  // initialize an unordered_set of int type
  unordered_set<int> numbers = {1, 100, 10, 70, 100};

  // print the set
  // Esto aun es un set, entonces 100 solo sale 1 vez y este no tiene orden
  cout << "Numbers are: ";
  for(auto &num: numbers) {
    cout << num << ", ";
  }

  return 0;
}