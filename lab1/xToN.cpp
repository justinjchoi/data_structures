// Justin Choi jc8mc 23/01/2017 xToN.cpp

#include <iostream>
using namespace std; 

int xton (int a, int b) {
  if (b == 0) {
    return 1; 
  }
  else {
    return a * xton(a, b-1); 
  }
}

int main() {
  int x, y;
  cout << "What is the first value? ";  
  cin >> x;  
  cout << "What is the second value? "; 
  cin >> y; 
  int z; 
  z = xton(x, y); 
  cout << x << " ^ " << y << " =  " << z << endl; 
  return 0; 
}

