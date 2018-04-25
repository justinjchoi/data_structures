// Justin Choi (jc8mc)
// January 28th 2017 
// ListItr.cpp 

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include <string>
using namespace std; 

// Constructor
ListItr :: ListItr() 
{
  current  = new ListNode(); 
}

// One Parameter Constructor 

ListItr :: ListItr(ListNode* theNode) 
{
  current = theNode; 
}

// isPastEnd() 

bool ListItr :: isPastEnd() const 
{
  return (current -> next == NULL); 
}

// isPastBeginning()

bool ListItr :: isPastBeginning() const 
{
  return (current -> previous == NULL); 
}

// moveForward() 

void ListItr :: moveForward() 
{
  if (!isPastEnd()) 
    current =  current ->  next; 
}

void ListItr :: moveBackward() 
{
  if (!isPastBeginning())
    current =  current ->  previous; 
}

int ListItr :: retrieve() const 
{
  return current -> value; 
}
