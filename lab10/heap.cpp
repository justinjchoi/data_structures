// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#include "heap.h"
#include "huffmanNode.h"
#include <iostream>
using namespace std;

heap::heap():huff_vect(101), curr_size(0){}

heap::~heap(){
  // same as makeEmpty()
  curr_size = 0;
  huff_vect.clear();
}

bool heap::isEmpty(){
  if (curr_size == 0) {
    return true; 
  }
  else {
    return false; 
  }
}

int heap::getSize(){
  return curr_size;
}

void heap::insert(huffmanNode* n){
  if(curr_size == huff_vect.size() - 1) {
    huff_vect.resize(huff_vect.size() * 2);
  }
  int hole = ++curr_size;
  // from percolateUp()
  for(; hole>1 && *n < *huff_vect[hole/2]; hole /= 2) {
    huff_vect[hole] = huff_vect[hole/2];
  }
  huff_vect[hole] = n;
}

void heap::deleteMin(){
  if(isEmpty())
    cout<< "You cannot call deleteMin on an empty heap" << endl;
  huff_vect[1] = huff_vect[curr_size--];
  int child;
  int hole = 1; 
  huffmanNode* temp = huff_vect[hole];
  // from percolateDown()
  for(;hole*2 <= curr_size; hole = child) {
    child = hole*2;
    if(child != curr_size && *huff_vect[child+1] < *huff_vect[child]) {
      child++;
    }
    if(*huff_vect[child] < *temp) {
      huff_vect[hole] = huff_vect[child];
    }
    else {
      break;
    } 
  }
  huff_vect[hole] = temp;
}
    
huffmanNode* heap::findMin(){
  return huff_vect[1];
}

vector<huffmanNode*> heap::getVect(){
  return huff_vect;
}
