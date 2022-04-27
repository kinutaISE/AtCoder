# include <iostream>
# include <vector>
# include <math.h>
using namespace std ;

int N, integer_bound, score_bound ;
const int DIVISION = 998244353 ;


int main() {
  cin >> N >> integer_bound >> score_bound ;

  int pattern_num = 0 ;
  int temp = integer_bound ;
  while (temp < DIVISION) {
    pattern_num++ ;
    temp *= integer_bound ;
  }

  vector<int> products(pattern_num) ;
  products.at(0) = integer_bound ;
  for (int i = 1 ; i < pattern_num ; i++)
    products.at(i) = integer_bound * products.at(i - 1) ;

  vector<int> coefficients(pattern_num) ;
  int residual = integer_bound ;
  for (int p = pattern_num - 1 ; p > -1 ; p--) {
    coefficients.at(p) = residual / (p + 1) ;
    residual /= p + 1 ;
  }

  integer_bound %= DIVISION ;

  int res = pow(integer_bound, coefficients.at(0)) ;
  for (int p = 1 ; p < pattern_num ; p++) {
    res *= pow(integer_bound, coefficients.at(p)) ;
    if (res > DIVISION)
      res %= DIVISION ;
  }
  cout << res << endl ;
}
