// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 9th 2017 
#include <iostream> 
using namespace std; 

int threexplusone(int x) {
  if (x == 0) {
    cout << 0 << endl; 
    return 0; 
  }
  if (x == 1) {
    cout << 1 << endl; 
    return 1; 
  } 
  else if (x % 2 == 0) {
    x = x / 2;
    cout << x << endl; 
    return threexplusone(x);  
  }
  else {
    x = 3 * x + 1;
    cout << x << endl; 
    return threexplusone(x); 
  }
}

int main() {
  int y; 
  cin >> y; 
  threexplusone(y);
  return 0; 
}
