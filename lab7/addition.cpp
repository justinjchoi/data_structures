// Justin Choi (jc8mc) 
// March 17th 2017 
// CS 2150 - 106, Lab 7: IBCM 

// C++ code for addition.ibcm 

#include <iostream> 

using namespace std; 

int main() {
  int first; 
  int second; 
  int third; 
  int intArray[3];  
  int sum = 5; 
  while (sum != 0) {
    int i = 0; 
    while (i < 3) {
      int x; 
      cin >> x; 
      intArray[i] = x;  
      i += 1; 
    }
    first = intArray[0]; 
    second = intArray[1]; 
    third = intArray[2]; 
    sum = first + second + third;
  }
  cout << first << endl; 
  cout << second << endl; 
  cout << third << endl; 
  return 0; 
} 
