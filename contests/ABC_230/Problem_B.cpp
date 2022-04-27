#include <iostream>
#include <algorithm>
using namespace std ;

int pow(int x, int y) {
  if (y == 1)
    return x ;
  return x * pow(x, y - 1) ;
}

int main() {
  string T = "" ;
  int len = pow(10, 5) ;
  for (int i = 0 ; i < len ; i++)
    T += "oxx" ;

  string S ;
  cin >> S ;
  for (int i = 0 ; i < T.size() - S.size() ; i++) {
    int contains = 1 ;
    for (int j = 0 ; j < S.size() ; j++)
      contains &= (T.at(i + j) == S.at(j)) ;
    if (! contains) continue ;
    cout << "Yes" << endl ;
    return 0 ;
  }
  cout << "No" << endl ;
}
