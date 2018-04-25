// Justin Choi (jc8mc) 31/01/2017 List.cpp 

#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
#include <string>
using namespace std; 

List :: List() {
  head = new ListNode(); 
  tail = new ListNode();
  head -> next = tail;  
  head -> previous = NULL; 
  tail -> previous = head; 
  tail -> next = NULL;    
  count = 0; 
}

List :: List(const List& source) {      // Copy Constructor
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

// Destructor
List :: ~List() {
  makeEmpty(); 
  delete tail; 
  delete head;
}
 
List& List::operator=(const List& source) { //Equals operator
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List :: isEmpty() const {
  if (count == 0) 
    return true; 
  else
    return false; 
}

void List :: makeEmpty() {
  ListItr a = first();
  ListNode * tmp;
  while(!a.isPastEnd()) {
      a.current->previous->next = a.current->next;
      tmp = a.current;
      a.current->next-> previous = a.current -> previous;
      a.moveForward();
      delete tmp;
  }
  count = 0; 
}

ListItr List :: first() {
  ListItr itr; 
  itr.current = head -> next;  
  return itr; 
} 

ListItr List :: last() {
  ListItr itr; 
  itr.current = tail -> previous; 
  return itr; 
}

void List :: insertAfter(int x, ListItr position) {
  ListNode *new_node = new ListNode(); 
  ListNode *current_node = position.current; 
  ListNode *next_node = current_node -> next; 
  new_node -> value = x; 
  new_node -> previous = current_node; 
  new_node -> next = next_node;
  current_node -> next = new_node; 
  next_node -> previous = new_node; 
  count++;
}

void List :: insertBefore(int x, ListItr position) {
  ListNode *new_node = new ListNode(); 
  ListNode *current_node = position.current; 
  ListNode *previous_node = current_node -> previous;
  new_node -> value = x;  
  new_node -> previous = previous_node; 
  new_node -> next = current_node; 
  current_node -> previous = new_node;
  previous_node -> next = new_node;  
  count++;  
}

void List :: insertAtTail(int x) {
  ListNode *new_node = new ListNode();
  ListNode *previous_node = tail -> previous;  
  new_node -> value = x; 
  new_node -> previous = previous_node; 
  new_node -> next = tail; 
  previous_node -> next = new_node; 
  tail -> previous = new_node; 
  count++; 
}

void List :: remove(int x) {
  ListItr itr1 = find(x);
  if (itr1.current -> next != NULL) {
    ListNode *pos=itr1.current;
    ListNode *prevNode=pos->previous;
    ListNode *nextNode=pos->next;
    prevNode->next=nextNode;
    nextNode->previous=prevNode;
    count--;
  }
  else {
    cout << "Cannot remove since not in the list" << endl; 
  } 
}


ListItr List :: find(int x) {
  ListItr itr1=first();
  while(!itr1.isPastEnd()) {
    if(itr1.current->value==x) {
      return itr1;
    }
    else {
      itr1.moveForward();
    }
  }
  return itr1;
}

int List :: size() const {
  return count; 
}

void printList (List& source, bool direction) {
  ListItr *forward_itr = new ListItr(source.first()); 
  ListItr *backward_itr = new ListItr(source.last());
  if (direction) {
    while (!forward_itr -> isPastEnd()) {
      cout << forward_itr -> retrieve(); 
      forward_itr -> moveForward(); 
    }
  }
  else {
    while (!backward_itr -> isPastBeginning()) {
      cout << backward_itr -> retrieve(); 
      backward_itr -> moveBackward(); 
    }
  }
} 
