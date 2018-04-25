// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>
using namespace std;

class huffmanNode {
 public:
  huffmanNode(int freq, char l);
  ~huffmanNode();
  huffmanNode *left, *right;
  int freq;
  char letter; 
  string code;
  bool operator<(const huffmanNode& n) const;
  void printNode();
  int getFreq()const;
  string getPrefix();
  char getLetter();
  void printCode();
};
#endif
