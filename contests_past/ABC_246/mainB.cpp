#include <iostream>
#include <cmath>
using namespace std ;

int main() {
  double a, b ;
  cin >> a >> b ;
  double c = sqrt( a * a + b * b ) ;
  cout << a / c << " " << b / c << endl ;
}
