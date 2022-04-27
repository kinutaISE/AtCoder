#include <iostream>
using namespace std ;

int main() {
  int p ;
  cin >> p ;

  // パターン1
  if (p == 1) {
    int price ;
    int n ;
    cin >> price >> n ;
    cout << n * price << endl ;
  }

  // パターン2
  if (p == 2) {
    string text ;
    int price ;
    int n ;
    cin >> text >> price >> n ;
    cout << text << "!" << endl ;
    cout << n * price << endl ;
  }
}
