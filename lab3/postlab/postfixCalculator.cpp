// Justin Choi (jc8mc) 04/02/2017 postfixCalculator.cpp 

#include "postfixCalculator.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
#include "Stack.h"

#include <iostream>
#include <string>
using namespace std; 

postfixCalculator :: postfixCalculator() {
}

postfixCalculator :: ~postfixCalculator() {
}

void postfixCalculator :: pushNum(int x) {
  stack_ptr.push(x); 
}

void postfixCalculator :: add() {
  int first; // Get first value 
  first = stack_ptr.top(); // use top() to get the value on top
  stack_ptr.pop(); // remove the element on the top 
  int second; 
  second = stack_ptr.top(); 
  stack_ptr.pop(); 
  int summed; 
  summed = first + second; 
  stack_ptr.push(summed); 
}

void postfixCalculator :: subtract() {
  int first = stack_ptr.top(); 
  stack_ptr.pop(); 
  int second = stack_ptr.top(); 
  stack_ptr.pop(); 
  int subtracted = second - first; 
  stack_ptr.push(subtracted);
}

void postfixCalculator :: multiply() {
  int first = stack_ptr.top(); 
  stack_ptr.pop(); 
  int second = stack_ptr.top(); 
  stack_ptr.pop(); 
  int multiplied = first * second; 
  stack_ptr.push(multiplied); 
}

void postfixCalculator :: divide() {
  int first = stack_ptr.top(); 
  stack_ptr.pop(); 
  int second = stack_ptr.top(); 
  stack_ptr.pop(); 
  int divided = second / first; 
  stack_ptr.push(divided); 
}

void postfixCalculator :: negate() {
  int first = stack_ptr.top(); 
  stack_ptr.pop(); 
  int negated = -1 * first; 
  stack_ptr.push(negated); 
}

int postfixCalculator :: getTopValue() {
  int topReturnValue = stack_ptr.top(); 
  return topReturnValue; 
}
