// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include "huffmanNode.h"

using namespace std;

class heap{
 public:
  heap(); // constructor
  ~heap(); // destructor 
  void insert(huffmanNode* n); // insert, later on have to implement percolateUp
  huffmanNode* findMin(); // always the first 
  int getSize(); 
  bool isEmpty(); 
  void deleteMin(); // percolateDown later  
  vector<huffmanNode*> getVect();
 private:
  int curr_size;
  vector<huffmanNode*> huff_vect;
};

#endif
