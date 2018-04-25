// Justin Choi (jc8mc) 31/01/2017 ListItr.cpp 

#include "ListItr.h"
#include "ListNode.h"
#include <iostream>
#include <string>
using namespace std; 

// Constructor
ListItr :: ListItr() {
  current = new ListNode(); 
}

// One POINTER  parameter Constructor 
ListItr :: ListItr(ListNode *theNode) {
  current = theNode; // pointer point to the other pointer  
}

bool ListItr :: isPastEnd() const {
  return (current -> next == NULL); 
}

bool ListItr :: isPastBeginning() const {
  return (current -> previous == NULL); 
}

void ListItr :: moveForward() {
  if (!isPastEnd()) {
    current = current -> next; 
  }
}

void ListItr :: moveBackward() {
  if (!isPastBeginning()) {
    current = current -> previous; 
  }
}

int ListItr :: retrieve() const {
  return current -> value; 
}



