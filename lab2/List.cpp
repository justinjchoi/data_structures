// Justin Choi (jc8mc) 
// January 28th 2017 
// List.cpp 

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include <string>
using namespace std; 

#include <iostream>
#include "List.h"

using namespace std;

List::List(){

  head = NULL;
  tail = NULL;
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous= head;
  count= 0;
  
}

List::List(const List& source) {      // Copy Constructor
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


List::~List(){
  makeEmpty();
  delete tail;
  delete head;
}

bool List::isEmpty () const {
  if (count == 0)
    return true;
  else 
    return false;
}

void List::makeEmpty () {// remove all the nodes between dummy head and tail
  ListItr a = first();
  ListNode * tmp;
  while(!a.isPastEnd())
    {
      a.current->previous->next = a.current->next;
      tmp = a.current;
      a.current->next-> previous = a.current -> previous;
      a.moveForward();
      delete tmp;
    }
}

ListItr List::first(){
  if(!isEmpty()){
    return ListItr(head->next);
  }
  else
    return ListItr(tail);
}

ListItr List::last(){
  if(!isEmpty()){
    return ListItr(tail->previous);
  }
  else
    return ListItr(head);
}

void List::insertAfter(int x, ListItr position){
  /*
  ListNode * nex = position.current -> next;
  ListNode * nn = new ListNode ();
  nn->value  = x;
  nex -> previous = nn;
  nn-> next = nex;
  position.current -> previous->next = nn;
  nn -> previous = position.current->previous;
  */
  
  ListNode * LN = new ListNode();
  ListNode * tmp;
  LN -> previous = position.current;
  LN -> next = position.current->next;
  tmp = position.current -> next;
  position.current->next = LN;
  ListItr(tmp).current->previous = LN;
  LN-> value =x;
  
  count++;
}

void List::insertBefore(int x, ListItr position){
  /*
  ListNode * bef = position.current -> previous; 
  ListNode * nn = new ListNode ();
  nn->value  = x;
  bef -> next = nn;
  nn-> next = position.current;
  position.current-> previous = nn;
  nn -> previous = bef;
  */
  
  ListNode * LN = new ListNode();
  ListNode * tmp;
  LN -> next = position.current;
  LN -> previous = position.current-> previous;
  tmp = position.current -> previous; 
  position.current->previous = LN;
  ListItr(tmp).current -> next = LN;
  LN -> value = x;
  
  count++;
}

void List::insertAtTail(int x){//am I replacing with tail or what?
  /*   
  ListNode * LN = new ListNode();
  ListNode * tmp;
  ListItr a = ListItr(head->previous);
  tmp = a.current ->next;
  LN->next = tail;
  LN->previous = a.current;
  a.current-> next = LN;
  ListItr(tmp).current -> previous = LN;
  LN -> value =x;
  */
  
  ListNode * bef = tail -> previous; 
  ListNode * nn = new ListNode ();
  nn->value  = x;
  bef -> next = nn;
  nn-> next = tail;
  tail -> previous = nn;
  nn -> previous = bef;
  
  count++;
}

void List::remove (int x){
  ListItr a = find(x);
  ListNode * tmpNext;
  ListNode * tmpPrevious;
  tmpNext = a.current -> next;
  tmpPrevious = a.current -> previous; 
  a.current->previous->next = tmpNext;
  a.current->next->previous = tmpPrevious;   
  delete a.current; 
}

ListItr List::find(int x) {
  ListItr a = first();
  int y = a.current->value;
  if(!isEmpty()){
    while (y!= x){
      
      a.moveForward();
      y= a.current->value;
    }
    return a; 
  }
  else
    return ListItr(tail);
}

int List::size()const {
  if(!isEmpty())
      
    return count;
  else
       
    return 0;
   
}

void printList(List& theList, bool direction){
  
  ListItr h = theList.first();
  ListItr t = theList.last();
  
  if (direction){
    while(!h.isPastEnd()){ 
      cout << h.retrieve();
      h.moveForward();
    }
  }
  else{
    while(!t.isPastBeginning()){
      cout << t.retrieve();
      t.moveBackward();
    }
  }
}
