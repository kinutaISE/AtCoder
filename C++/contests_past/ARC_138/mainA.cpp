#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std ;

bool is_feasible(vector< pair<int, int> >& a, int k) {
  int min_first = a[0].first ;
  for (int i = 1 ; i < k ; i++)
    min_first = min(min_first, a[i].first) ;
  int max_latter = a[k].first ;
  for (int i = k + 1 ; i < a.size() ; i++)
    max_latter = max(max_latter, a[i].first) ;
  return min_first < max_latter ;
}

int main() {
  int N, K ;
  cin >> N >> K ;
  vector< pair<int, int> > list_vi(N) ;
  for (int i = 0; i < N; i++) {
    cin >> list_iv[i].first ;
    list_iv[i].second = i ;
  }

  if (! is_feasible(list, K)) // 可能かどうかの判定
    cout << -1 << endl ;

  sort(list.begin() + K + 1, list.end()) ;
  int ans = N ;
  for (int i = 0 ; i < K ; i++) {
    
  }
  cout << ans << endl ;
}
