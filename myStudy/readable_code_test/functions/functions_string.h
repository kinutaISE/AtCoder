#ifndef READEF1_R_20220514_EIHZBI89139_INCLUDE_
#define READEF1_R_20220514_EIHZBI89139_INCLUDE_

#include <iostream>
#include <vector>

using namespace std ;

// プロトタイプ /////////////////////////////////
vector<string> split(const string* str, const char del) ;

///////////////////////////////////////////////

// 定義 ///////////////////////////////////////
vector<string> split(const string str, const char del) {
  // 文字列 str を del を区切り文字として分割し、その結果を string 型のベクトルとして返す
  vector<string> result(1) ;
  int length_result = 1 ;

  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      length_result++ ;
      continue ;
    }
    result[length_result] += c ;
  }

  return result ;
}

////////////////////////////////////////////////////////////////

#endif
