#include <iostream>
#include <vector>
#include <cmath>

using namespace std ;

int N, M, K ;
vector< vector<int64_t> > dp_table ;
void dp_count_core(int i, int b) {
  // if (b <= i) {
  //   dp_table[i][b] = 0 ;
  //   return ;
  // }
  if (i == 0) {
    dp_table[i][b] = (b >= 1) ? min(M, b) : 0 ;
    return ;
  }
  int64_t count = 0 ;
  for (int l = min(b, M) ; l >= 1 ; l--) {
    int ub = b - l ;
    if (dp_table[i - 1][ub] == -1)
      dp_count_core(i - 1, ub) ;
    count += dp_table[i - 1][ub] ;
  }
  dp_table[i][b] = count % 998244353 ;
}
void dp_count() {
  dp_table = vector< vector<int64_t> >(N, vector<int64_t>(K + 1)) ;
  for (int i = 0 ; i < N ; i++) {
    for (int b = 0 ; b < K + 1 ; b++)
      dp_table[i][b] = -1 ;
  }
  dp_count_core(N - 1, K) ;
}

int main() {
  cin >> N >> M >> K ;

  dp_count() ;

  cout << dp_table[N - 1][K] << endl ;
}
