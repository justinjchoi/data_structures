// Justin Choi (jc8mc) 
// CS 2150 - 106 
// April 18th 2017 

#include "heap.h"
#include "huffTree.h"
#include "huffmanNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main (int argc, char **argv) {
  int compressed = 0; 

  if (argc != 2) {
    cout << "Input file must be the one and only parameter" << endl;
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");

  int distinct_count = 0;
  char g;
  int freq[128]; 
  for(int i=0; i<128; i++) {
    freq[i]=0;
  } 

  int num = 0;
  while ( (g = fgetc(fp)) != EOF ){
    int asc_val=(int) g; // cast to int for ASCII
    if(asc_val > 31 && asc_val < 128) {
      freq[asc_val]++;
      num++;
    }
  }

  heap myHeap1;
  int i = 1; 
  while (i < 128) {
    if(freq[i] > 0) {
      huffmanNode* temp = new huffmanNode(freq[i], (char) i);
      myHeap1.insert(temp);
      distinct_count++;
    }
    i++; 
  }

  huffTree* myTree = new huffTree();
  heap myHeap2 = myTree -> makeHuffmanTree(myHeap1);
  myTree -> printPrefix(myHeap2.findMin(), "");
  myTree -> setPrefix(myHeap2.findMin(),"");
    
  cout << "---------------------------------------------------------------" << endl;

  rewind(fp);

  vector<huffmanNode*> myVector = myHeap1.getVect();
 
  while ((g = fgetc(fp)) != EOF) {
    int a = 1; 
    while (a <= myHeap1.getSize()) {
      if (myVector[a] -> getLetter() == g) {
	cout << myVector[a] -> getPrefix() << " ";
	compressed += myVector[a] -> getPrefix().size();
      }
      a++; 
    }
  }
    
  cout << endl;

  cout << "---------------------------------------------------------------" << endl;

  cout << "There are a total of " << num << " symbols that are encoded." << endl;
  cout << "There are "<< distinct_count << " distinct symbols used." << endl;
  cout << "There were "<< num * 8 << " bits in the original file." << endl;
  cout << "There were "<< compressed << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of "<< (double) num * 8 / compressed << "." << endl;
  cout << "The cost of the Huffman Tree is "<< (double) compressed / num <<" bits per character." << endl;

  fclose(fp);
  return 0;
}
