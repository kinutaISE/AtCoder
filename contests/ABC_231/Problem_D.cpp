#include <iostream>
#include <vector>
using namespace std ;

int main() {
  int N, M ;
  cin >> N >> M ;
  vector< vector<int> > adj_list(N, vector<int>(0)) ;
  for (int i = 0 ; i < M ; i++) {
    int a, b ;
    cin >> a >> b ;
    a-- ;
    b-- ;
    adj_list.at(a).push_back(b) ;
    adj_list.at(b).push_back(a) ;
  }

  vector<bool> discoverd(N) ;

  for (int i = 0 ; i < N ; i++) {
    if (discoverd.at(i)) continue ;
    if (adj_list.at(i).size() != 1) continue ;
    discoverd.at(i) = true ;
    int prev = i ;
    int next = adj_list.at(i).at(0) ;
    while (true) {
      if (discoverd.at(next)) {
        cout << "No" << endl ;
        return 0 ;
      }
      discoverd.at(next) = true ;
      if (adj_list.at(next).size() == 1)
        break ;
      if (adj_list.at(next).size() > 2) {
        cout << "No" << endl ;
        return 0 ;
      }
      int temp = next ;
      next = adj_list.at(next).at(0) == prev ? adj_list.at(next).at(1) : adj_list.at(next).at(0) ;
      prev = temp ;
    }
  }
  cout << "Yes" << endl ;
}
