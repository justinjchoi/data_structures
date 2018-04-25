#include <iostream> 
using namespace std; 

int power(int x, int y) {
  if (y == 1) {
    return x; 
  }
  else {
    return x * power(x, y - 1); 
  }
}

int main() {
  int first = 5; 
  int second = 3; 
  int powered = power(first, second); 
  cout << powered << endl; 
}
