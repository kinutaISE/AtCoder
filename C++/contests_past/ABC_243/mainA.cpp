#include <iostream>

using namespace std ;

int main() {
  int V, A, B, C ;
  cin >> V >> A >> B >> C ;

  V %= (A + B + C) ;
  if (V < A) cout << "F" << endl ;
  else if (V - A < B) cout << "M" << endl ;
  else cout << "T" << endl ;
}
