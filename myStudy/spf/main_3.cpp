#include <iostream>

using namespace std ;

const int LOWER_BOUND = 0 ;
const int UPPER_BOUND = 9999 ;

const int TARGET = 7 ;

int count_target ;

void add_target(int num) {
  while (num > 0) {
    count_target += (num % 10 == TARGET) ? 1 : 0 ;
    num /= 10 ;
  }
}

int main() {
  count_target = 0 ;
  for (int v = LOWER_BOUND ; v <= UPPER_BOUND ; v++)
    add_target(v) ;
  cout << count_target << endl ;
  return 0 ;
}
