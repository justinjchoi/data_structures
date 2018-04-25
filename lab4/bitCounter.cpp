// Justin Choi (jc8mc) 16/02/2017 bitCounter.cpp 

#include <iostream> // for cout 
#include <math.h> // for floor 
#include <stdlib.h> // for atoi
using namespace std; 

int recursiveBinNum(int n) {
  int count; 
  // base case (takes care of zero)
  if (n == 0) {
    count = 0; 
    return count;  
  }
  // recursive (when n is even) 
  else if (n % 2 == 0) {
    count = recursiveBinNum(n / 2); 
    return count; 
  }
  // recursive (when n is odd)
  else {
    count = 1 + recursiveBinNum(floor(n/2)); 
    return count; 
  }
}


int main(int argc, char **argv) {
  int y = atoi(argv[1]); 
  cout << "Number of 1-bit(s) for " << y << ": " <<  recursiveBinNum(y) << endl;  
  return 0; 
}
