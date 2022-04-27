#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std ;

int main() {
  int N ;
  cin >> N ;
  vector<int> numbers(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> numbers[i] ;
  int Q ;
  cin >> Q ;
  vector< vector<int> > queries(Q, vector<int>(4)) ;
  int max_X = 0 ;
  for (int j = 0 ; j < Q ; j++) {
    cin >> queries[j][0] >> queries[j][1] >> queries[j][2] ;
    queries[j][0]-- ;
    queries[j][1]-- ;
    queries[j][3] = j ;
    max_X = max(max_X, queries[j][2]) ;
  }

  vector< vector< pair<int, pair<int, int>> > > queries_X(max_X + 1) ;
  for (auto q : queries)
    queries_X[ q[2] ].push_back( make_pair( q[3], make_pair(q[0], q[1])) ) ;

  vector< pair<int, int> > ans ;
  for (int X = 1 ; X <= max_X ; X++) {
    vector<int> appear(N) ;
    int count = 0 ;
    for (int i = 0 ; i < N ; i++) {
      if (numbers[i] != X) continue ;
      count++ ;
      appear[i] = count ;
    }

    for (auto q : queries_X[X]) {
      int count_l = 0 ;
      for (int l = q.second.first - 1 ; l > -1 ; l--) {
        if (appear[l] == 0) continue ;
        count_l = appear[l] ;
        break ;
      }
      int count_r = 0 ;
      for (int r = q.second.second ; r >= q.second.first ; r--) {
        if (appear[r] == 0) continue ;
        count_r = appear[r] ;
        break ;
      }
      if (count_r > 0)
        ans.push_back( make_pair(q.first, count_r - count_l) ) ;
      else
        ans.push_back( make_pair(q.first, 0) ) ;
    }
  }

  sort(ans.begin(), ans.end()) ;

  for (auto p : ans)
    cout << p.second << endl ;
}
