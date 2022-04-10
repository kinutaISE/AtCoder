#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <stack>

using namespace std ;

int node_num, edge_num ;
vector< vector< pair<int, int> > > adj_list ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

int get_start_node(vector<int> node_status) {
  for (int v = 0 ; v < node_num ; v++)
    if (node_status[v] == UNDISCOVERED) return v ;
  return -1 ;
}

int find_max_pos(vector<int> vec) {
  int max_pos = 0 ;
  for (int i = 1 ; i < vec.size() ; i++)
    max_pos = (vec[i] > vec[max_pos]) ? i : max_pos ;
  return max_pos ;
}

int get_start_node(vector<int> node_status, vector<int> label) {
  int max_pos = find_max_pos(label) ;
  if (label[max_pos] == -1) return -1 ;
  return max_pos ;
}

int main() {
  cin >> node_num >> edge_num ;

  adj_list = vector< vector< pair<int, int> > >(node_num, vector< pair<int, int> >(0)) ;
  for (int i = 0 ; i < edge_num ; i++) {
    int tail, head ;
    cin >> tail >> head ;
    tail-- ;
    head-- ;
    adj_list[tail].push_back( make_pair(i, head) ) ;
  }
  // 深さ優先探索（開始頂点0から帰りがけ順にラベリング）
  vector<int> label(node_num, -1) ;
  int pos = 0 ;
  vector<int> node_status(node_num, UNDISCOVERED) ;
  stack<int> node_stack ;
  while (true) {
    int s = get_start_node(node_status) ;
    if (s == -1) break ;
    node_stack.push(s) ;
    node_status[s] = DISCOVERED ;
    while (! node_stack.empty()) {
      int u = node_stack.top() ;
      int next = -1 ;
      for (auto edge_info : adj_list[u]) {
        if (node_status[edge_info.second] != UNDISCOVERED)
          continue ;
        next = edge_info.second ;
        break ;
      }
      if (next == -1) {
        node_status[u] = PROCESSED ;
        label[u] = pos ;
        pos++ ;
        node_stack.pop() ;
        continue ;
      }
      node_status[next] = DISCOVERED ;
      node_stack.push(next) ;
    }
  }

  // 辺が逆向きのグラフ作成
  vector< vector< pair<int, int> > > adj_list_rev(node_num, vector< pair<int, int> >(0)) ;
  for (int u = 0 ; u < node_num ; u++) {
    for (pair<int, int> edge_info : adj_list[u]) {
      int index = edge_info.first ;
      int v = edge_info.second ;
      adj_list_rev[v].push_back( make_pair(index, u) ) ;
    }
  }

  // 辺が逆向きのグラフで深さ優先探索
  int ans = 0 ;
  node_stack = stack<int>() ;
  node_status = vector<int>(node_num, UNDISCOVERED) ;

  while (true) {
    int s = get_start_node(node_status, label) ;
    if (s == -1) break ;
    node_stack.push(s) ;
    node_status[s] = DISCOVERED ;
    label[s] = -1 ;
    int size_scc = 1 ;
    while (! node_stack.empty()) {
      int u = node_stack.top() ;
      int next = -1 ;
      for (auto edge_info : adj_list_rev[u]) {
        if (node_status[edge_info.second] != UNDISCOVERED)
          continue ;
        next = edge_info.second ;
        size_scc++ ;
        break ;
      }
      if (next == -1) {
        node_status[u] = PROCESSED ;
        label[u] = -1 ;
        node_stack.pop() ;
        continue ;
      }
      node_status[next] = DISCOVERED ;
      node_stack.push(next) ;
    }
    ans += size_scc * (size_scc - 1) / 2 ;
  }

  cout << ans << endl ;
}
