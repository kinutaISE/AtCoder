#include <iostream>
#include <string>

using namespace std ;

int main() {
  // 入力の受けとり
  string s ;
  cin >> s ;
  // 答えの計算
  if ( (s.at(0) == s.at(1)) && (s.at(1) == s.at(2)) )
    cout << -1 << endl ;
  else {
    cout <<
      ( s.at(0) == s.at(1) ?
       s.at(2) :
        (
          s.at(0) == s.at(2) ? s.at(1) : s.at(0)
        )
      )
    << endl ;
  }
  return 0 ;
}