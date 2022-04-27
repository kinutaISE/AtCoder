#include <iostream>
#include <iomanip>

using namespace std ;

int main() {
  cout << fixed << setprecision(10) ;

  double A, B, C, X ;
  cin >> A >> B >> C >> X ;

  double probability = 0.0 ;
  if (X <= A) probability = 1.0 ;
  else if (X <= B) probability = C / (B - A) ;

  cout << probability << endl ;
}
