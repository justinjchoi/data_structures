// Justin Choi (jc8mc)
// CS 2150 - 106  
// April 18th 2017 

#include "huffmanNode.h"
#include <iostream>
using namespace std;

huffmanNode::huffmanNode(int freqVal, char l){
  freq = freqVal;
  letter = l;
  code = "";
  left = NULL;
  right = NULL;
}

huffmanNode::~huffmanNode(){
  delete left;
  delete right;
}

int huffmanNode::getFreq() const{
  return freq;
}

void huffmanNode::printCode(){
  cout << "letter: " << letter << " code is: " << code <<endl;
}

bool huffmanNode::operator<(const huffmanNode& n) const{
  return(this -> getFreq() < n.getFreq());
}

void huffmanNode::printNode(){
  cout<< "frequency" << this -> getFreq() << "  char: " << letter << endl; 
}

string huffmanNode::getPrefix(){
  return code;
}

char huffmanNode::getLetter(){
  return letter;
}
