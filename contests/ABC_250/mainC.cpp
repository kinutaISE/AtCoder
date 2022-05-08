#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main() {
  int64_t ball_num, query_num ;
  cin >> ball_num >> query_num ;
  vector<int64_t> balls(ball_num + 1) ;
  vector<int64_t> positions(ball_num + 1) ;
  for (int64_t i = 1 ; i <= ball_num ; i++) {
    balls[i] = i ;
    positions[i] = i ;
  }

  int64_t x ;
  for (int64_t q = 0 ; q < query_num ; q++) {
    cin >> x ;
    int pos = positions[x] ;
    int swap_pos = (pos < ball_num) ? pos + 1 : pos - 1 ;
    swap(balls[pos], balls[swap_pos]) ;
    swap(positions[ balls[pos] ], positions[ balls[swap_pos] ]) ;
  }

  for (int i = 1 ; i < ball_num ; i++)
    cout << balls[i] << ' ' ;
  cout << balls[ball_nuber]<< endl ;
}
