#include <iostream> 

using namespace std; 

int main() {
  int myArray[3] = {1, 2, 3}; 
  int max = 0 ; 
  int i = 0; 
  while (i < 3) { 
    if (myArray[i] > max) {
      max = myArray[i]; 
    }
    i += 1; 
  }
  cout << max << endl; 
  return 0; 
}
