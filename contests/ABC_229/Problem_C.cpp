#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <algorithm>
using namespace std;

int64_t N, W ;
vector< pair<int64_t, int64_t> > cheese_info ;
/*
  cheese_info.first: チーズの美味しさ
  cheese_info.second: 何gあるか
*/

int main() {
  cin >> N >> W ;
  cheese_info = vector< pair<int64_t, int64_t> >(N) ;
  for (int64_t i = 0 ; i < N ; i++)
    cin >> cheese_info.at(i).first >> cheese_info.at(i).second ;

  sort(cheese_info.begin(), cheese_info.end()) ;

  int64_t residual = W ;
  int64_t evaluation = 0 ;
  for (int64_t i = N - 1 ; i > -1 ; i--) {
    pair<int64_t, int64_t> c = cheese_info.at(i) ;
    if (residual == 0)
      break ;
    int64_t added_num = min(residual, c.second) ;
    evaluation += c.first * added_num ;
    residual -= added_num ;
  }

  cout << evaluation << endl ;
}
