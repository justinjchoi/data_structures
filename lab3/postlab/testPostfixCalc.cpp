// Justin Choi (jc8mc) 04/02/2017 testPostfixCalc.cpp

#include <iostream>
#include "postfixCalculator.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cstring>
using namespace std; 

int main() {
  postfixCalculator p;
  cout << "Enter the values you want the Postfix Calculator to calculate seperated by spaces" << endl; 

  while (true) {
    string s; 
    cin >> s; 
    if (s == "") {
      break; 
    }
    const char* cstr = s.c_str();

    if(isdigit(cstr[0])) {
      int x = atoi(cstr); 
      p.pushNum(x); 
    }

    if (s[0] == '-' && s.length() > 1) {
      int x = atoi(cstr); 
      p.pushNum(x); 
    } 

    if (s == "+") {
      p.add(); 
    }

    if (s == "-") {
      p.subtract(); 
    }

    if (s == "/") {
      p.divide(); 
    }

    if (s == "*") {
      p.multiply(); 
    }

    if (s == "~") {
      p.negate(); 
    }
  }

  cout << "Result is: " << p.getTopValue() << endl;
  return 0;
}
