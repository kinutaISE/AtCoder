#include <iostream>

using namespace std ;

int main() {
  int a, b ;
  cin >> a >> b ;
  if (a == 1) {
    if (b == 2 || b == 10)
      cout << "Yes" << endl ;
    else
      cout << "No" << endl ;
  }
  else if (a == 10) {
    if (b == 1 || b == 9)
      cout << "Yes" << endl ;
    else
      cout << "No" << endl ;
  }
  else {
    if (b == a - 1 || b == a + 1)
      cout << "Yes" << endl ;
    else
      cout << "No" << endl ;
  }
}
