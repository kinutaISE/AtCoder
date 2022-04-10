#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {
  int list_size ;
  cin >> list_size ;
  vector<int> list(list_size) ;
  for (int i = 0 ; i < list.size() ; i++)
    cin >> list[i] ;

  sort(list.begin(), list.end()) ;

  if (list[0] > 0) {
    cout << 0 << endl ;
    return 0 ;
  }
  int prev = 0 ;
  for (int i = 1 ; i < list.size() ; i++) {
    if (list[i] > prev + 1) break ;
    prev = list[i] ;
  }
  cout << prev + 1 << endl ;
}
