#include <iostream> 
using namespace std; 

int produce(int x, int y) {
  int producted = 0; 
  while (y >= 1) {
    producted += x; 
    y--; 
  }
  return producted; 
}

int main() {
  int first = 3; 
  int second = 2; 
  int myProduct = produce(first, second); 
  cout << myProduct << endl; 
  return 0; 
}
