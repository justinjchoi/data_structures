#include <iostream> 
using namespace std; 

class Justin {
public: 
  virtual void one(); 
  virtual void two(); 
}; 

class Choi: public Justin {
public: 
  void one(); 
  void two(); 
}; 

void Justin::one() {
  cout << "Justin's one" << endl; 
}

void Choi::one() {
  cout << "Choi's one" << endl; 
}

void Justin::two() {
  cout << "Justin's two" << endl; 
}

void Choi::two() {
  cout << "Choi's two" << endl; 
}

int main() {
  Justin *j = new Choi(); 
  j -> one(); 
  return 0; 
}
