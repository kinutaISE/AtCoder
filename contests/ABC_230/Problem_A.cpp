#include <iostream>
#include <string>
using namespace std ;

int main() {
  int N ;
  cin >> N ;

  if (N >= 42) N++ ;

  string index ;

  if (N < 10)
    index = "00" + to_string(N) ;
  else
    index = "0" + to_string(N) ;

  cout << "AGC" << index << endl ;
}
