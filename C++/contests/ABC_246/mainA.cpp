#include <iostream>
#include <vector>
using namespace std ;

vector<string> split(string str, char del) {
  vector<string> result ;

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

int main() {
  vector< vector<int> > coordinates ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    auto data = split(line, ' ') ;

  }
}
