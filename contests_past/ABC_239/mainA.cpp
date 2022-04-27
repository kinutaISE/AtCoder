#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std ;

int main() {
  cout << fixed << setprecision(10) ;

  double height ;
  cin >> height ;

  cout << sqrt( height * (12800000 + height) ) << endl ;
}
