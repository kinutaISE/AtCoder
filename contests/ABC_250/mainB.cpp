#include <iostream>

using namespace std ;

int main() {
  int N, A, B ;
  cin >> N >> A >> B ;

  string line_even = "" ;
  for (int k = 0 ; k < N ; k++) {
    for (int j = 0 ; j < B ; j++) {
      line_even += (k % 2 == 0) ? "." : "#" ;
    }
  }
  string line_odd = "" ;
  for (int k = 0 ; k < N ; k++) {
    for (int j = 0 ; j < B ; j++) {
      line_odd += (k % 2 == 0) ? "#" : "." ;
    }
  }

  for (int k = 0 ; k < N ; k++) {
    string line = (k % 2 == 0) ? line_even : line_odd ;
    for (int i = 0 ; i < A ; i++)
      cout << line << endl ;
  }
}
