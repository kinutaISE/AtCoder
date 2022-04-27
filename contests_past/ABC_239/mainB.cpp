#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std ;

int main() {
  cout << fixed << setprecision(18) ;

  long double x ;
  cin >> x ;

  cout << int64_t( floor(x / 10) ) << endl ;
}
