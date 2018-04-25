// Justin Choi (jc8mc) 
// March 14th 2017 
// CS 2150-106 Lab 6: Hashing

#include "hashTable.h"
#include <math.h> 

using namespace std;

hashTable::hashTable(int size) {
  if(checkforprime(size)) {
    table_size = 2*size;
  }
  // table_size = size makes it slower
  else {
    table_size = getNextPrimeNum(2*size);
    // table_size = getNextPrimeNum(size); makes it slwoer 
  }
  myBucket = new vector<list<string> >;
  int i = 0; 
  while (i < table_size) {   
    list<string> temp;
    myBucket -> push_back(temp);
    i++; 
  }
}

hashTable::~hashTable() {
  delete myBucket;
}

void hashTable::add(string str){
  int hash_index = hash_func(str); 
  myBucket -> at(hash_index).push_back(str);
}

bool hashTable::contain(string theWord) {
  list<string> & theList = myBucket -> at(hash_func(theWord));
  for(list<string> :: iterator itr = theList.begin(); itr != theList.end(); itr++) {
    if(theWord == *itr) {
      return true;
    }
  }
  return false;
}

bool hashTable::checkforprime(unsigned int num_check) {
  if (num_check <= 1) 
    return false;
  if (num_check == 2)
    return true;
  if (num_check % 2 == 0) 
    return false;
  for (int i = 3; i*i <= num_check; i += 2) 
    if (num_check % i == 0 )
      return false;
  return true;
}

int hashTable::getNextPrimeNum(unsigned int num_get) {
  while (!checkforprime(++num_get));
  return num_get; 
}

int hashTable::hash_func(string myKey) {
  /*
  // Original 
  unsigned int num_func = 0;
  const int len = myKey.length()/2 + 1;
  for(int i = 0; i < len; i += 2) {
    num_func = num_func * i + myKey[i];
  }
  return num_func % table_size;
  */
  
// better hash function
  int num_func = 0;
  for (int i = 0; i < myKey.length(); i++) {
    num_func = num_func + myKey[i]; 
  }
  return num_func % table_size;
  
// better hash function by multiplying by constant
/*
  int num_func = 0;
  int len = myKey.length();
  int i = 0; 
  while (i < len) {
    num_func = 23 * num_func + myKey[i]; 
    i += 2; 
  }
  num_func = num_func % table_size; 
  return (num_func < 0 ? (num_func + table_size) : num_func); 
*/

  // return 0; worse hash function  

}


