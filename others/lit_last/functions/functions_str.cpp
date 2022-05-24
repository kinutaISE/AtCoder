#ifndef FUNCTION_STR_IAOOCI8914_INCLUDED_
#define FUNCTION_STR_IAOOCI8914_INCLUDED_

#include <string>
#include <vector>

using namespace std ;

// 定義 //////////////////////////////////////////////////////////
vector<string> split(const string str, const char del) ;

// 実装 //////////////////////////////////////////////////////////
vector<string> split(const string str, const char del) {
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

#endif
