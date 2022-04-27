#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
  int64_t price ;
  vector<int64_t> values(3) ;
  cin >> price >> values[0] >> values[1] >> values[2] ;
  sort(values.begin(), values.end()) ;
  reverse(values.begin(), values.end()) ;

  int64_t min_num = 9999 ;

  for (int64_t i = price / values[0] ; i > -1 ; i--) {
    int64_t residual = price - values[0] * i ;
    for (int64_t j = residual / values[1] ; j > -1 ; j--) {
      int64_t residual2 = residual - values[1] * j ;
      if (residual2 % values[2] != 0) continue ;
      min_num = min( min_num, i + j + (residual2 / values[2]) ) ;
    }
  }
  cout << min_num << endl ;
}
