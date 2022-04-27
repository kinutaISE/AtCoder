#include <iostream>
using namespace std ;

int main() {
  int N, K, A ;
  cin >> N >> K >> A ;

  int last = A ;
  for (int i = 1 ; i < K ; i++) {
    last++ ;
    if (last > N)
      last = 1 ;
  }

  cout << last << endl ;
}
