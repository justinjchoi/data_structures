// Justin Choi (jc8mc) 09/02/2017 Stack.cpp 

#include "Stack.h"
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std; 

Stack :: Stack() {
}

bool Stack :: empty() {
  if (myStack.size() == 0) 
    return true; 
  else 
    return false;
}

int Stack :: top() {
  if (myStack.size() == 0) {
    cout << "ERROR: Stack is empty. Cannot retrieve top value." << endl;
    exit(-1); 
  }
  else {
    ListItr itr = myStack.first(); 
    int x = itr.retrieve(); 
    return x;
  } 
}

void Stack :: pop() {
  if (myStack.size() == 0) {
    cout << "ERROR: Stack is empty. Cannot pop top value." << endl; 
    exit(-1); 
  }
  else {
    ListItr itr = myStack.first(); 
    int y = itr.retrieve(); 
    myStack.remove(y);
  } 
}

void Stack :: push(int x) {
  ListItr itr = myStack.first(); 
  myStack.insertBefore(x, itr); 
}
