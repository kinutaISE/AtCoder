#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std ;

int pow(int x, int y) {
  if (y == 1) return x ;
  return x * pow(x, y - 1) ;
}

int main() {
  cout << fixed << setprecision(10) ;
  int64_t a, b, c ;
  cin >> a >> b >> c ;
  string ans = (a < pow(c, b)) ? "Yes" : "No" ;
  cout << ans << endl ;
}
