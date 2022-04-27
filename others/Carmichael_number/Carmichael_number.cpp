#include <iostream>
#include <algorithm>
using namespace std ;

int pow(int n, int m) {
  // n^m を返す関数
  if (m == 1)
    return n ;
  return n * pow(n, m - 1) ;
}

bool is_disjoint(int n, int m) {
  // 前提: n ≥ m
  // 整数 n, m が互いに素であるかを判定する
  for (int k = 2 ; k <= m ; k++) {
    if (n % k == 0 && m % k == 0)
      return false ;
  }
  return true ;
}

bool condition1(int n, int a, int s) {
  return pow(a, s) % n == 1 ;
}
bool condition2(int n, int a, int k, int s) {
  for (int i = 0 ; i <= k - 1 ; i++) {
    if (pow(a, (1 << i) * s) % n == n - 1)
      return true ;
  }
  return false ;
}

int main() {
  int n ;
  cin >> n ; // カーマイケル数を受け取る（ここでは 561）

  // n = 2^k s + 1 としたときの，k, s を求める
  int pow_two = 2 ;
  int k = 0 ;
  for (int i = 1 ; pow_two <= n ; pow_two <<= 1, i++) {
    if ((n - 1) % pow_two != 0) continue ;
    k = i ;
  }
  int s = (n - 1) / (1 << k) ;
  cout << k << " " << s << endl ;
  // n と互いに素である，各 2 ≤ a < n に対して，条件を満たすか判定する.
  for (int a = 2 ; a < n ; a++) {
    if (! is_disjoint(n, a)) continue ;
    cout << "a = " << a << " : " ;
    if (condition1(n, a, s) || condition2(n, a, k, s)) {
      cout << "Yes" << endl ;
      continue ;
    }
    cout << "No" << endl ;
  }
  return 0 ;
}
