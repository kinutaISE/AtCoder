#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std ;

int N ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

vector<int> calculate_dists_dfs(int s, vector< set<int> > &adj_list) {
  vector<int> dists(N) ;

  vector<int> node_status(N) ;
  stack<int> container ;

  node_status.at(s) = DISCOVERED ;
  container.push(s) ;

  while (! container.empty() ) {
    int u = container.top() ;
    container.pop() ;
    for (int v : adj_list.at(u)) {
      if (node_status.at(v) != UNDISCOVERED)
        continue ;
      node_status.at(v) = DISCOVERED ;
      container.push(v) ;
      dists.at(v) = dists.at(u) + 1 ;
    }
    node_status.at(u) = PROCESSED ;
  }
  return dists ;
}
int find_max_dist_node(vector<int> &ds) {
  int max_dist = ds.at(0) ;
  int max_node = 0 ;
  for (int u = 1 ; u < N ; u++) {
    int dist = ds.at(u) ;
    if (max_dist >= dist)
      continue ;
    max_dist = dist ;
    max_node = u ;
  }
  return max_node ;
}
int find_max_dist(vector<int> &ds) {
  int max_dist = ds.at(0) ;
  for (int u = 1 ; u < N ; u++)
    max_dist = max(max_dist, ds.at(u)) ;
  return max_dist ;
}

int main() {
  cin >> N ;
  vector< set<int> > adj_list(N) ;
  for (int i = 0 ; i < N - 1 ; i++) {
    int u, v ;
    cin >> u >> v ;
    u-- ;
    v-- ;
    adj_list.at(u).insert(v) ;
    adj_list.at(v).insert(u) ;
  }
  vector<int> dists_0 = calculate_dists_dfs(0, adj_list) ;
  int max_node = find_max_dist_node(dists_0) ;
  vector<int> dists_max_node = calculate_dists_dfs(max_node, adj_list) ;
  cout << find_max_dist(dists_max_node) + 1 << endl ;
}

/*
方針：各頂点を始点として dfs を適用する．
計算量：O(N^2)

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

void set_dists_dfs(int s, vector< set<int> > &adj_list, vector< vector<int> > &ds) {
  vector<int> &ds_s = ds.at(s) ;

  stack<int> container ;
  vector<int> node_status(N) ;
  for (int u = 0 ; u < N ; u++)
    node_status.at(u) = UNDISCOVERED ;

  container.push(s) ;
  node_status.at(s) = DISCOVERED ;

  while (! container.empty()) {
    int u = container.top() ;
    container.pop() ;
    for (int v : adj_list.at(u)) {
      if (node_status.at(v) != UNDISCOVERED)
        continue ;
      container.push(v) ;
      node_status.at(v) = DISCOVERED ;
      ds_s.at(v) = ds_s.at(u) + 1 ;
    }
    node_status.at(u) = PROCESSED ;
  }
}
int find_max_dist(vector< vector<int> > &ds) {
  int max_dist = 0 ;
  for (int u = 0 ; u < N - 1 ; u++) {
    for (int v = u + 1 ; v < N ; v++)
      max_dist = max(max_dist, ds.at(u).at(v)) ;
  }
  return max_dist ;
}

int main() {
  cin >> N ;
  vector< set<int> > adj_list(N) ;
  for (int i = 0 ; i < N - 1 ; i++) {
    int u, v ;
    cin >> u >> v ;
    u-- ;
    v-- ;
    adj_list.at(u).insert(v) ;
    adj_list.at(v).insert(u) ;
  }

  vector< vector<int> > dists(N, vector<int>(N)) ;
  for (int u = 0 ; u < N ; u++) {
    for (int v = 0 ; v < N ; v++)
      dists.at(u).at(v) = 0 ;
  }

  for (int u = 0 ; u < N - 1 ; u++)
    set_dists_dfs(u, adj_list, dists) ;

  cout << find_max_dist(dists) + 1 << endl ;
}
*/
