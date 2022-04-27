#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <algorithm>
#include <set>
using namespace std ;

const int N = 1000 ;
vector< pair<int, int> > points_s(N) ;
vector< pair<int, int> > points_g(N) ;
const int ACCEPTING_NUM = 50 ;

void setInput() {
  for (int i = 0 ; i < N ; i++) {
    cin >> points_s.at(i).first >> points_s.at(i).second ;
    cin >> points_g.at(i).first >> points_g.at(i).second ;
  }
}
int abs(int x) {
  if (x < 0)
    return -1 * x ;
  return x ;
}
int getDist(int i) {
  return abs(points_s.at(i).first - points_g.at(i).first) + abs(points_s.at(i).second - points_g.at(i).second) ;
}
int getDist(pair<int, int> pa, pair<int, int> pb) {
  return abs(pa.first - pb.first) + abs(pa.second - pb.second) ;
}

vector<int> greedy_select() {
  /* 始点終点間の距離が小さいものを選択する */
  vector< pair<int, int> > p_di(N) ;
  for (int i = 0 ; i < N ; i++) {
    p_di.at(i).first = getDist(i) ;
    p_di.at(i).second = i + 1 ;
  }

  sort(p_di.begin(), p_di.end()) ;

  vector<int> subset(ACCEPTING_NUM) ;
  for (int i = 0 ; i < ACCEPTING_NUM ; i++)
    subset.at(i) = p_di.at(i).second ;

  return subset ;
}

vector<int> greedy_cycle(vector<int> subset) {
  vector<int> cycle(2 * ACCEPTING_NUM + 2);
  cycle.at(0) = -1 ;

  set<int> S ;
  for (int u : subset)
    S.insert(u - 1) ;

  /* 始点を表す頂点: 1 ~ 1000, 終点を表す頂点: 1001 ~ 2000 */
  set<int> selectable_vertices ;
  pair<int, int> current_point = make_pair(400, 400) ;

  int cycle_length = cycle.size() ;
  for (int i = 1 ; i < cycle_length - 1 ; i++) {
    int choice = -1 ;
    pair<int, int> choice_point ;
    int min_dist = 2000 ;
    for (int u : S) {
      int dist = getDist( current_point, points_s.at(u) ) ;
      if ( min_dist <= dist )
        continue ;
      choice = u ;
      choice_point = points_s.at(u) ;
      min_dist = dist ;
    }
    for (int u : selectable_vertices) {
      int dist = getDist( current_point, points_g.at(u - N) ) ;
      if ( min_dist <= dist )
        continue ;
      choice = u ;
      choice_point = points_g.at(u - N) ;
      min_dist = dist ;
    }

    cycle.at(i) = choice ;

    current_point = choice_point ;
    if (S.count(choice)) {
      selectable_vertices.insert(choice + N) ;
      S.erase(choice) ;
    }
    else
      selectable_vertices.erase(choice) ;
  }

  cycle.back() = -1 ;
  return cycle ;
}

void display_subset(vector<int> &subset) {
  int m = subset.size() ;
  cout << m << ' ' ;
  for (int i = 0 ; i < m - 1 ; i++)
    cout << subset.at(i) << ' ' ;
  cout << subset.back() << endl ;
}
void display_cycle(vector<int> &cycle) {
  int n = cycle.size() ;
  cout << n << ' ' ;
  cout << 400 << ' ' << 400 << ' ' ;
  for (int i = 1 ; i < n - 1 ; i++) {
    int u = cycle.at(i) ;
    if (u < N) {
      cout << points_s.at(u).first << ' ' << points_s.at(u).second << ' ' ;
      continue ;
    }
    u -= N ;
    cout << points_g.at(u).first << ' ' << points_g.at(u).second << ' ' ;
  }
  cout << 400 << ' ' << 400 << endl ;
}

int main() {
  setInput() ; // set input

  vector<int> subset = greedy_select() ; // select 50 points by greedy approach
  sort(subset.begin(), subset.end()) ;
  vector<int> cycle = greedy_cycle(subset) ;

  display_subset(subset) ;
  display_cycle(cycle) ;
}
