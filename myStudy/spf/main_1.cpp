#include <iostream>

using namespace std ;

const int YEAR_LOWER_BOUND = 0 ;
const int YEAR_UPPER_BOUND = 2020 ;

void show_ans(int year) {
  // 400 で割り切れる
  if (! (year % 400) ) {
    cout << "閏年です" << endl ;
  }
  // 400 で割り切れない、かつ、100 で割り切れる
  if (! (year % 100) ) {
    cout << "閏年ではありません" << endl ;
  }

  cout << ( year % 4 ? "閏年ではありません" : "閏年です") << endl ;
}

int main() {
  for (int y = YEAR_LOWER_BOUND ; y < YEAR_UPPER_BOUND ; y++)
    show_ans(y) ;
  return 0 ;
}
