# include <bits/stdc++.h>
using namespace std ;

int main() {
  int Q ;
  cin >> Q ;
  int64_t N = (1 << 20) ;
  vector<int> A(N) ;
  for (int i = 0 ; i < N ; i++)
    A.at(i) = -1 ;

  for (int i = 0 ; i < Q ; i++) {
    int t ;
    int64_t x ;
    cin >> t >> x ;
    if (t == 1) {
      int64_t h = x ;
      while (A.at(h % N) != -1)
        h++ ;
      A.at(h % N) = x ;
      continue ;
    }
    cout << A.at(x % N) << endl ;
  }
}
