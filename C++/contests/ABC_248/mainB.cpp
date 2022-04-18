#include <iostream>

using namespace std;

int main() {
  int64_t A, B, K ;
  cin >> A >> B >> K ;

  int64_t current = A ;
  int64_t count = 0 ;
  while (current < B) {
    count++ ;
    current *= K ;
  }
  cout << count << endl ;
}
