#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
using namespace std ;

int main() {
  int N, Q ;
  cin >> N >> Q ;
  vector<int> A(N) ;
  for (int i = 0; i < N; i++)
    cin >> A.at(i) ;
  vector< pair<int, int> > x(Q) ;
  for (int j = 0 ; j < Q ; j++) {
    cin >> x.at(j).first ;
    x.at(j).second = j ;
  }
  sort(A.begin(), A.end()) ;
  sort(x.begin(), x.end()) ;

  vector< pair<int, bool> > mixed_array(0) ;
  // A の要素である場合 => second が true, x の要素である => second が false
  int pos_A, pos_x ;
  while (pos_A < N || pos_x < Q) {
    if (pos_A == N) {
      while (pos_x != Q) {
        mixed_array.push_back( make_pair(x.at(pos_x).second, false) ) ;
        pos_x++ ;
      }
      break ;
    }
    if (pos_x == Q) {
      while (pos_A != N) {
        mixed_array.push_back( make_pair(A.at(pos_A), true) ) ;
        pos_A++ ;
      }
      break ;
    }
    if (x.at(pos_x).first <= A.at(pos_A)) {
      mixed_array.push_back( make_pair(x.at(pos_x).second, false) ) ;
      pos_x++ ;
      continue ;
    }
    mixed_array.push_back( make_pair(A.at(pos_A), true) ) ;
    pos_A++ ;
  }
  /*
  for (auto p : mixed_array) {
    cout << p.first << " " << p.second << endl ;
  }
  */
  vector<int> lessor_count(Q) ;
  for (int j = 0 ; j < Q ; j++)
    lessor_count.at(j) = N ;
  int count = 0 ;
  for (auto p : mixed_array) {
    if (p.second) {
      count++ ;
      continue ;
    }
    lessor_count.at(p.first) -= count ;
  }

  for (int lc : lessor_count)
    cout << lc << endl ;
}
