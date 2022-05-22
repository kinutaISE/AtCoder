#ifndef FUNCTION_STR_IAOOCI8914_INCLUDED_
#define FUNCTION_STR_IAOOCI8914_INCLUDED_

#include <vector>

using namespace std ;

vector<string> split(const string str, const char del) const ;

vector<string> split(const string str, const char del) {
  vector<string> result(1) ;

  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      continue ;
    }
    *result.end() += c ;
  }

  return result ;
}

#endif
