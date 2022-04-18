#include <iostream>

using namespace std ;

int get_divisor_num(int k) {
  int num = 2 ;
  for (int kk = 2 ; kk < k ; kk++)
    num += (k % kk == 0) ;
  return num ;
}

int main() {
  int n ;
  cin >> n ;
  int ans = 0 ;
  for (int k = 9 ; k <= n ; k += 2)
    if (get_divisor_num(k) == 8) ans++ ;
  cout << ans << endl ;
}
