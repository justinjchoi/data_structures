// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "huffmanNode.h"
#include "heap.h"

using namespace std;

class huffTree{
 public:
  huffTree();
  ~huffTree();
  huffmanNode *root; 
  heap makeHuffmanTree(heap h);
  void printPrefix(huffmanNode* root, string str);
  void setPrefix(huffmanNode* root, string str);
};
#endif
