// Justin Choi (jc8mc) 15/02/2017 inlab.cpp

#include <iostream>
using namespace std;

int main(){
  bool b = true;
  char c[] = "1";
  int i = 5;
  double d = 9.7;
  int* ip;
  cout<<"bool b: " << b <<endl;
  cout<<"char c: " << c <<endl;
  cout<<"int i: " << i <<endl;
  cout<<"double d: " << d <<endl;
  cout<<"int* ip: " << ip <<endl;


  int IntArray[10]={1,2,3,4,5,6,7,8,9,10};
  char CharArray[10]={'a','b','c','d','e','f','g','h','i','j'};


  int IntArray2D[6][5];

  for(int i=0; i<6; i++) {
    for(int j=0; j<5; j++) {
      IntArray2D[i][j];
    }
  }

  char CharArray2D[6][5];
  
  for(int i=0; i<6; i++){
    for(int j=0; j<5; j++){
      CharArray2D['i']['j'];
    }
  }

}
