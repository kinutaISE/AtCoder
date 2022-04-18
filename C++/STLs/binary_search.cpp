#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {
  vector<int> list{0, 0, 1, 1, 1, 3, 4, 5, 7, 7, 10, 10, 12, 30} ;

  for (int k = 0 ; k <= 30 ; k++) {
    cout << k << endl ;
    auto it_lower = lower_bound(list.begin(), list.end(), k) ;
    cout << "\tlower_bound(value): " << *it_lower << endl ; // 「k 以上」の値が現れる「最初の」イテレータ
    cout << "\tlower_bound(position): " << distance(list.begin(), it_lower) << endl ;
    auto it_upper = upper_bound(list.begin(), list.end(), k) ;
    cout << "\tupper_bound(value): " << *it_upper << endl ; // 「kより大きい」値が現れる「最初の」イテレータ
    cout << "\tupper_bound(position): " << distance(list.begin(), it_upper) << endl ;
  }
}
