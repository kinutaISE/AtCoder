#include <iostream>
#include <vector>
#include <cstdint>
using namespace std ;

int main() {
  int n ;
  cin >> n ;

  vector<int64_t> lucas(n + 1) ;
  lucas.at(0) = 2LL ;
  lucas.at(1) = 1LL ;
  for (int i = 2 ; i <= n ; i++)
    lucas.at(i) = lucas.at(i - 1) + lucas.at(i - 2) ;
  cout << lucas.at(n) << endl ;
}
