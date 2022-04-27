#include <iostream>
using namespace std ;

int main() {
  int n, a ;
  cin >> n >> a ;

  // ここにプログラムを追記
  for (int i = 1 ; i <= n ; i++) {
    string op ;
    int b ;
    cin >> op >> b ;
    if (op == "+")
      a += b ;
    if (op == "-")
      a -= b ;
    if (op == "*")
      a *= b ;
    if (op == "/") {
      if (b == 0) {
        cout << "error" << endl ;
        break ;
      }
      a /= b ;
    }
    cout << i << ":" << a << endl ;
  }
}
