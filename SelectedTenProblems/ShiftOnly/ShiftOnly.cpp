#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

int main() {
  int N ;
  cin >> N ;
  vector<int> numbers(N) ;
  for (int i = 0; i < N ; i++)
    cin >> numbers.at(i) ;

  int minimum_count = INT_MAX ;
  for (int v : numbers) {
    if (v & 1) {
      minimum_count = 0 ;
      break ;
    }
    v >>= 1 ;
    int count = 1 ;
    while (! (v & 1)) {
      count++ ;
      v >>= 1 ;
    }
    minimum_count = min(minimum_count, count) ;
  }
  cout << minimum_count << endl ;
}
