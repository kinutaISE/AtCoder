#include <iostream>

using namespace std ;

bool is_ACGT(char c) {
  return (c == 'A' || c == 'C' || c == 'G' || c == 'T') ;
}

int main() {
  string str ;
  cin >> str ;

  str += " " ;
  int max_length = 0 ;
  int current_length = 0 ;
  for (char c : str) {
    if (! is_ACGT(c)) {
      max_length = max(max_length, current_length) ;
      current_length = 0 ;
      continue ;
    }
    current_length++ ;
  }

  cout << max_length << endl ;
}
