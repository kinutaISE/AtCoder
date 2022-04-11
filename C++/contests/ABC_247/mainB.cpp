#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

int N ;
vector< pair<string, string> > names ;

bool is_overlapped(int k, string str) {
  for (int i = 0 ; i < N ; i++) {
    if (i == k) continue ;
    if (names[i].first == str || names[i].second == str)
      return true ;
  }
  return false ;
}

bool ans ;
void bt_search(int k) {
  if (k == N) {
    ans = true ;
    return ;
  }
  if (is_overlapped(k, names.at(k).first) && is_overlapped(k, names.at(k).second))
    return ;
  bt_search(k + 1) ;
}
void bt_search() {
  ans = false ;
  bt_search(0) ;
}

int main() {
  cin >> N ;
  names = vector< pair<string, string> >(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> names.at(i).first >> names.at(i).second ;

  bt_search() ;
  if (ans) {
    cout << "Yes" << endl ;
    return 0 ;
  }
  cout << "No" << endl ;
}
