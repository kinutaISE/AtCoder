#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stack>

using namespace std ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;
bool is_reachable_dfs(int s, int t, vector< vector<int> > adj_list) {
  stack<int> container ;
  vector<int> node_status(adj_list.size()) ;
  container.push(s) ;
  node_status[s] = DISCOVERED ;
  while ( !container.empty() ) {
    int current = container.top() ;
    container.pop() ;
    if (current == t)
      return true ;
    for (int v : adj_list[current]) {
      if (node_status[v] == UNDISCOVERED) {
        node_status[v] = DISCOVERED ;
        container.push(v) ;
      }
    }
  }
  return false ;
}

int main() {
  cout << fixed << setprecision(30) ;
  // 入力の受け取り
  int circle_num ; // 円の個数
  cin >> circle_num ;
  pair<double, double> start ; // 始点の座標
  cin >> start.first >> start.second ;
  pair<double, double> goal ; // 終点の座標
  cin >> goal.first >> goal.second ;
  vector< pair<double, double> > points ; // 円の中心座標
  vector<double> radiuses ;
  for (int i = 0; i < circle_num ; i++) {
    double x, y ;
    double r ;
    cin >> x >> y >> r ;
    points.push_back( make_pair(x, y) ) ;
    radiuses.push_back(r) ;
  }
  // 始点が乗っている円を求める
  int start_index = -1 ;
  for (int i = 0 ; i < circle_num ; i++) {
    double dist = hypot(points[i].first - start.first, points[i].second - start.second) ;
    if (dist != radiuses[i])
      continue ;
    start_index = i ;
    break ;
  }
  // 終点が乗っている円を求める
  int goal_index = -1 ;
  for (int i = 0 ; i < circle_num ; i++) {
    double dist = hypot(points[i].first - goal.first, points[i].second - goal.second) ;
    if (dist != radiuses[i])
      continue ;
    goal_index = i ;
    break ;
  }
  // グラフを作成する
  vector< vector<int> > adj_list(circle_num) ;
  for (int i = 0 ; i < circle_num - 1 ; i++) {
    for (int j = i + 1 ; j < circle_num ; j++) {
      double dist = hypot(
        points[i].first - points[j].first,
        points[i].second - points[j].second
      ) ;
      if (dist > radiuses[i] + radiuses[j])
        continue ;
      if (dist < abs(radiuses[i] - radiuses[j]))
        continue ;
      adj_list[i].push_back(j) ;
      adj_list[j].push_back(i) ;
    }
  }
  // 深さ優先探索を行う
  cout <<
    ( is_reachable_dfs(start_index, goal_index, adj_list) ? "Yes" : "No" )
  << endl ;

  return 0 ;
}
