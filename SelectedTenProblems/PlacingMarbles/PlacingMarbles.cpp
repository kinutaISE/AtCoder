#include <iostream>
#include <string>
using namespace std ;

int main() {
  string s ;
  cin >> s ;

  int sum = 0 ;
  for (int i = 0 ; i < 3 ; i++) {
    if (s.at(i) == '0')
      continue ;
    sum++ ;
  }

  cout << sum << endl ;
}
