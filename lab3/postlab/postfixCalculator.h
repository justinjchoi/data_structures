#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"
#include <string>
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
  Stack stack_ptr;   
}; 

#endif 
