#include <iostream>
#include <string>
using namespace std ;

int main() {
  /* 文字列の初期化 */
  string s ; // string 型のオブジェクト宣言
  cout << "Initializing by \"string s ;\"" << endl ;
  cout << "Result : " << s << endl ;

  string ss(5, 'a') ; // 'aaaaa' で初期化
  cout << "Initializing by \"string ss(5, 'a') ;\"" << endl ;
  cout << "Result : " << ss << endl ;

  string sss("abc") ; // "abc" で初期化
  cout << "Initializing by \"string ss(\"abc\") ;\"" << endl ;
  cout << "Result : " << sss << endl ;

  return 0 ;
}
