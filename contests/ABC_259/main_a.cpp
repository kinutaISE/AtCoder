#include <iostream>

using namespace std ;

int main() {
  int N, M, X, T, D ;
  cin >> N >> M >> X >> T >> D ;
  // 0 歳時点の身長を求める
  int T_0 = T - D * X ;
  // 身長を求める
  cout << T_0 + D * min(M, X) << endl ;
  return 0 ;
}
