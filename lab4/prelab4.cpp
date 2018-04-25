// Justin Choi (jc8mc) 12/02/2017 prelab4.cpp

#include <iostream> 
#include <string>
#include <limits>
#include <cstdlib>

using namespace std; 

void sizeOfTest() { 
  cout << "Size of int: " << sizeof(int) << endl; 
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl; 
  cout << "Size of float: " << sizeof(float) << endl; 
  cout << "Size of double: " << sizeof(double) << endl; 
  cout << "Size of char: " << sizeof(char) << endl; 
  cout << "Size of bool: " << sizeof(bool) << endl; 
  cout << "Size of int*: " << sizeof(int*) << endl; 
  cout << "Size of char*: " << sizeof(char*) << endl; 
  cout << "Size of double*: " << sizeof(double*) << endl;  
}

void outputBinary(unsigned int x) {
  string output_binary; 
  if (x == 0) {
    output_binary = "0000 0000 0000 0000 0000 0000 0000 0000"; 
  }
  for (int i = 31; i > -1; i--) {
    if (x & (1 << i)) {
      output_binary += "1"; 
    }
    else {
      if (output_binary.length() > 0) {
	output_binary += "0"; 
      }
    }
  }
  cout << "The above in binary is " << output_binary << endl; 
}

void overflow() {
  unsigned int r = std::numeric_limits<unsigned int>::max();
  // 4294967295, found online how to compute the max of unsigned int
  cout << "Before adding 1: " << r << endl; 
  r = r + 1; 
  cout << "After adding 1: " << r << endl;
  cout << "Since the maximum value of unsigned int is represented in binary, a sequence of thirty-two 1's. If you try to add one to this number, it results in one 1's and thirty-two 0's. As the 1 is in the 33rd place, it disappears, leaving the ultimate result of 0." << endl;    
}




int main() {
  cout << "sizeOfTest(): " << endl; 
  cout << "" << endl; 
  sizeOfTest();
  cout << "" << endl; 

  cout << "outputBinary(): " << endl; 
  cout << "" << endl; 
  string s; 
  cout << "Provide a number that you wish to convert in 32-bit binary: "; 
  cin >> s; 
  int x = atoi(s.c_str());
  outputBinary(x); 
  cout << "" << endl; 

  cout << "overflow():" << endl;
  cout << "" << endl;  
  overflow();  
  cout << "" << endl; 
  return 0; 
}
