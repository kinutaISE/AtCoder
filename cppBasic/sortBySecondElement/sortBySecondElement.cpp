#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
  int n ;
  cin >> n ;

  vector< pair<int, int> > pairs(n) ;
  for (auto &p : pairs)
    cin >> p.second >> p.first ;

  sort(pairs.begin(), pairs.end()) ;
  for (auto &p : pairs) {
    swap(p.first, p.second) ;
    cout << p.first << ' ' << p.second << endl ;
  }
}
