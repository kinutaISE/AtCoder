#include "prot_type_functions.h"
#include <iostream>

using namespace std ;

int main() {
  int x, y ;
  cin >> x >> y ;
  cout << func(x, y) << endl ;
}

int func(int x, int y) {
  return 2 * x + y ;
}
