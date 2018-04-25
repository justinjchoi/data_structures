// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#include "huffmanNode.h"
#include "huffTree.h"
#include "heap.h"
#include <string>

using namespace std;

huffTree::huffTree(){
  root = NULL;
}

huffTree::~huffTree(){
  delete root;
}

heap huffTree::makeHuffmanTree(heap h){
  while(h.getSize() >= 2){
    huffmanNode* x = h.findMin();
    h.deleteMin();
    huffmanNode* y = h.findMin();
    h.deleteMin();
    // deleteMin twice as learned in lecture to create huffman tree 
    int freq_sum = 0;
    freq_sum += (x -> getFreq());
    freq_sum += (y -> getFreq());
    huffmanNode* merged = new huffmanNode (freq_sum,'1'); // dummy 
    merged -> left = x;
    merged -> right = y;
    h.insert(merged);
  }
  return h;
}

void huffTree::setPrefix (huffmanNode *root, string str) {
  if (root -> left == NULL && root -> right == NULL) {
    root -> code = str;
  }
  if (root -> left) {
    setPrefix(root -> left, str + "0");
  }
  if (root -> right) { 
    setPrefix(root -> right, str + "1");
  }
}

void huffTree::printPrefix(huffmanNode *root, string str) {
  if (root -> letter == ' ') {
    cout << "space" << " " << str << endl;
  }
  if (root -> left == NULL && root -> right == NULL && root -> letter != ' ') {
    cout<< root -> letter <<"  "<< str << endl;
  }
  if (root -> left) {
    printPrefix(root -> left, str + "0");
  }
  if (root -> right) {
    printPrefix(root -> right, str + "1");
  }
}
