// Justin Choi (jc8mc) 09/02/2017 Stack.h 

#ifndef STACK_H
#define STACK_H

#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std; 

class Stack {
 public: 
  Stack(); 
  void push(int x); 
  void pop(); 
  bool empty(); 
  int top(); 

 private:
  List myStack; 
};

#endif
