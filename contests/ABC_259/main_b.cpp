#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std ;

int main() {
  cout << fixed << setprecision(10) ;
  // 入力の受け取り
  double a, b, d ;
  cin >> a >> b >> d ;
  // 新しい座標を求める
  d *= M_PI / 180 ;
  double ap = a * cos(d) - b * sin(d) ;
  double bp = a * sin(d) + b * cos(d) ;
  cout << ap << ' ' << bp << endl ;
  return 0 ;
}
