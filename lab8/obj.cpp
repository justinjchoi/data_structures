class obj {
public:
  obj(); 
  int a;
  char c;
  float f;
  double d; 
  char *ptr; 
};

obj :: obj() {
  a = 1;
  c = 'x';
  f = 2.0;
  d = 3.5;
  *ptr = 'p';
}

int main() {
  obj o;
  return 0; 
}



