#include <iostream>
#include <vector>
using namespace std ;

int main() {
  // lower_boud が見つけるものが，よりインデックスの小さなものなのかどうかを調べる
  vector<int> container{0, 1, 2} ;

  auto lb = lower_bound(container.begin(), container.end(), 2) ;
  cout << *lb << endl ;
  cout << distance(container.begin(), lb) ;

  return 0 ;
}
