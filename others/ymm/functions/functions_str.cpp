////////////////////////////////////////////////////////////////
/*
./functions/functions_str.cpp
文字列操作に関する関数の実装
*/

#ifndef STR_CPP_AIKVCIAOBH78194_INCLUDED_
#define STR_CPP_AIKVCIAOBH78194_INCLUDED_

#include <vector>
#include <string>

using namespace std ;

// 文字列 str を区切り文字 del として分割し、ベクトルとして返す関数
vector<string> split(string str, char del) {
  vector<string> result(1) ;
  int pos = 0 ;

  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result[pos] += c ;
  }

  return result ;
}

#endif // STR_CPP_AIKVCIAOBH78194_INCLUDED_

////////////////////////////////////////////////////////////////
