# include <iostream>
using namespace std ;

int main() {
  int S, T, X ;
  cin >> S >> T >> X ;

  if (S == T) {
    cout << "No" << endl ;
    return 0 ;
  }

  if (S < T) {
    if (X >= S && X < T)
      cout << "Yes" << endl ;
    else
      cout << "No" << endl ;
  }
  else {
    if (X >= S || X < T)
      cout << "Yes" << endl ;
    else
      cout << "No" << endl ;
  }
}
