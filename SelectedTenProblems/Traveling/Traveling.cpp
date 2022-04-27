#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

int N ;

int abs(int k) {
  if (k < 0)
    return -k ;
  return k ;
}
int get_dist(pair<int, int> p, pair<int, int> pp) {
  return abs(p.first - pp.first) + abs(p.second - pp.second) ;
}
bool is_feasible_travel(vector<int> &ts, vector< pair<int, int> > &ps) {
  for (int i = 1 ; i <= N ; i++) {
    int time_interval = ts.at(i) - ts.at(i - 1) ;
    int dist = get_dist(ps.at(i - 1), ps.at(i)) ;
    int two_k = time_interval - dist + 2 ;
    if (two_k <= 0)
      return false ;
    if (two_k & 1)
      return false ;
  }
  return true ;
}

int main() {
  cin >> N ;
  vector<int> times(N + 1) ;
  vector< pair<int, int> > points(N + 1) ;
  times.at(0) = 0 ;
  points.at(0).first = points.at(0).second = 0 ;
  for (int i = 1 ; i <= N ; i++) {
    cin >> times.at(i) ;
    cin >> points.at(i).first >> points.at(i).second ;
  }

  if (is_feasible_travel(times, points)) {
    cout << "Yes" << endl ;
    return 0 ;
  }
  cout << "No" << endl ;
}
