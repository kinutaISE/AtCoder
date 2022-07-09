#include <iostream>
#include <string>

using namespace std ;

bool remakable(string S, string T) {
  // 左側から調べていく
  // 初めの文字から違う場合 false
  if ( S.at(0) != T.at(0) )
    return false ;
  // 初めの文字は等しい場合
  int current = 0 ;
  while ( current < T.length() - 1 ) {
    // S の末尾の場合
    if ( current + 1 == S.length() ) {
      // T の次の文字が現在の文字と違う場合 false
      if ( S.at(current) != T.at(current + 1) )
        return false ;
      // T の次の文字が 1 つ前の文字と違う場合 false
      if ( S.at(current - 1) != T.at(current + 1) )
        return false ;
      S.insert( current + 1, {S.at(current)} ) ;
    }
    else if ( S.at(current + 1) != T.at(current + 1) ) {
      // 次の文字が現在の文字と違う場合 false
      if ( S.at(current) != T.at(current + 1) )
        return false ;
      // 同じ場合、現在の文字と前と同じ文字でなければ false
      if ( S.at(current) != S.at(current - 1) )
        return false ;
      S.insert( current + 1, {S.at(current)} ) ;
    }
    current++ ;
  }
  return true ;
}

int main() {
  // 入力の受け取り
  string S, T ;
  cin >> S >> T ;
  // 結果の出力
  cout << ( ( remakable(S, T) ) ? "Yes" : "No" ) << endl ;
  return 0 ;
}
