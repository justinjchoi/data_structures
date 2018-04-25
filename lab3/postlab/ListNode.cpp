// Justin Choi (jc8mc) 31/01/2017 ListNode.cpp 

#include "ListNode.h"
#include <iostream>
#include <string>
using namespace std; 

// ListNode Constructor
ListNode :: ListNode() {
  value = 0; // holding value
  next = NULL; // pointers to null to give initializer value 
  previous = NULL; // same thing above, other direction 
}

