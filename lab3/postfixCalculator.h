#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <string>
#include <stack>
using namespace std; 

class postfixCalculator {
 public:
  postfixCalculator(); 
  ~postfixCalculator(); 
  void pushNum(int x); 
  void add(); 
  void subtract(); 
  void multiply(); 
  void divide(); 
  void negate(); 
  int getTopValue(); 
 
 private:
  stack<int> *stack_ptr;  
}; 

#endif 
