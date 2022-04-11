#include <iostream>
#include <vector>
#include <utility>

using namespace std ;

const int64_t INSERT = 1 ;
const int64_t PICKUP = 2 ;

int main() {
  int64_t query_num ;
  cin >> query_num ;

  vector< pair<int64_t, int64_t> > value_num ;
  int head = 0 ;
  for (int64_t i = 0 ; i < query_num ; i++) {
    int64_t query_type ;
    cin >> query_type ;
    if (query_type == INSERT) {
      int64_t value, num ;
      cin >> value >> num ;
      value_num.push_back( make_pair(value, num) ) ;
      continue ;
    }
    int64_t num ;
    cin >> num ;
    int64_t total = 0 ;
    for (int i = head ; i < value_num.size() ; i++) {
      auto& v_n = value_num[i] ;
      if (num == 0) break ;
      int64_t pick_num = min(num, v_n.second) ;
      total += v_n.first * pick_num ;
      v_n.second -= pick_num ;
      if (v_n.second == 0) head++ ;
      num -= pick_num ;
    }
    cout << total << endl ;
  }
}
