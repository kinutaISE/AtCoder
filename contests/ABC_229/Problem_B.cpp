#include <iostream>
using namespace std;

int main() {
  int64_t A, B ;
  cin >> A >> B ;

  bool is_hard = false ;

  while (A > 0 && B > 0) {
    int a = A % 10 ;
    int b = B % 10 ;
    if (a + b >= 10) {
      is_hard = true ;
      break ;
    }
    A /= 10 ;
    B /= 10 ;
  }
  if (is_hard)
    cout << "Hard" << endl ;
  else
    cout << "Easy" << endl ;
}
