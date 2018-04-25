// Justin Choi (jc8mc) 
// March 14th 2017 
// CS 2150-106 Lab 6: Hashing

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream> 
#include <vector> 
#include <list> 
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

class hashTable {
 public:
  hashTable(int size);
  ~hashTable();
  void add(string str);
  bool contain(string str);
  bool checkforprime(unsigned int num_check);
  int getNextPrimeNum(unsigned int num_get);
  int hash_func(string myKey);
 private:
  vector< list <string> > *myBucket;
  int table_size; 

};

#endif
