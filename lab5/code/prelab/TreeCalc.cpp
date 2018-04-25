// Justin Choi (jc8mc) 28/02/2017 CS 2150-106 

#include "TreeCalc.h"
#include "TreeNode.h"
#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  myStack = stack<TreeNode*>(); 
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  while(myStack.size() != 0) {
    cleanTree(myStack.top()); 
    myStack.pop(); 
  }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr -> left != NULL) {
    cleanTree(ptr -> left); 
    cleanTree(ptr -> right); 
  }
  else {
    delete ptr;
  } 
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if (val == "+" || val == "-" || val == "*" || val == "/") {
    TreeNode *newNode = new TreeNode(val); 
    newNode -> left = myStack.top(); 
    myStack.pop(); 
    newNode -> right = myStack.top(); 
    myStack.pop(); 
    myStack.push(newNode); 
  }
  else {
    TreeNode *newNode2 = new TreeNode(val); 
    myStack.push(newNode2); 
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (ptr -> left != NULL || ptr -> right != NULL) {
    cout << ptr -> value; 
    cout << " "; 
    printPrefix(ptr -> right); 
    cout << " "; 
    printPrefix(ptr -> left); 
  }
  else {
    cout << ptr -> value; 
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  if (ptr -> left != NULL) {
    if (ptr -> value == "+" || ptr -> value == "-" || ptr -> value == "*" || ptr -> value == "/") {
      cout << "("; 
      printInfix(ptr -> right); 
      cout << " "; 
      cout << ptr -> value; 
      cout << " "; 
      printInfix(ptr -> left); 
      cout << ")"; 
    }
    else { 
      cout << ptr -> value; 
    }
  }
  else {
    cout << ptr -> value; 
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if (ptr -> left != NULL || ptr -> right != NULL) {
    printPostfix(ptr -> right); 
    cout << " "; 
    printPostfix(ptr -> left); 
    cout << " "; 
    cout << ptr -> value; 
  }
  else {
    cout << ptr -> value; 
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (myStack.size()!=0 && myStack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        printPostfix(myStack.top()); 
        cout << endl;
        cout << "Expression tree in infix expression: ";
        printInfix(myStack.top()); 
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        printPrefix(myStack.top()); 
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  int return_Val = 0; 
  if (ptr -> value == "+") {
    int right = calculate(ptr->right);
    int left = calculate(ptr->left);
    return_Val += (right+left);
    return return_Val; 
  }
  else if (ptr -> value == "*") {
    int right = calculate(ptr->right);
    int left = calculate(ptr->left);
    return_Val += (right*left);
    return return_Val;
  }
  else if (ptr -> value == "-") {
    int right = calculate(ptr->right);
    int left = calculate(ptr->left);
    return_Val += (right-left);
    return return_Val;
  }
  else if(ptr -> value == "/"){
    int right = calculate(ptr->right);
    int left = calculate(ptr->left);
    return_Val += (right/left);
    return return_Val;
  }
  else {
    return atoi((ptr->value).c_str());
  } 
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    while (myStack.size() != 0) {
      i += calculate(myStack.top()); 
      myStack.pop(); 
    }
    return i;
}
