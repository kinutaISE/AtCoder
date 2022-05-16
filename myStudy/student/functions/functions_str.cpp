// 文字列操作に関する種々の関数の実装（定義は functions_str.h）

#include "functions_str.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

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

int find(const char* ss[], string str) {
  const char* str_c = str.c_str();
  for (int i = 0; str_c[i] != '\0' ; i++)
    if ( strcmp(ss[i], str_c) ) return i ;
  return -1 ;
}
