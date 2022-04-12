#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

bool is_reachable_dfs(vector< vector<int> > adj_list, int s, int t) {
  int node_num = adj_list.size() ;
  stack<int> node_stack ;
  vector<int> node_status(node_num) ;

  node_stack.push(s) ;
  node_status[s] = DISCOVERED ;
  while (! node_stack.empty()) {
    int u = node_stack.top() ;
    int v = -1 ;
    for (int i = 0 ; i < adj_list[u].size() ; i++) {
      if (node_status[ adj_list[u][i] ] != UNDISCOVERED)
        continue ;
      v = adj_list[u][i] ;
      if (v == t) return true ;
      node_stack.push(v) ;
      node_status[v] = DISCOVERED ;
      break ;
    }
    if (v != -1) continue ;
    node_stack.pop() ;
    node_status[u] = PROCESSED ;
  }
  return false ;
}

int main() {
  int length, upper_bound ;
  cin >> length >> upper_bound ;
  vector<int> list_a(length) ;
  for (int i = 0 ; i < length ; i++)
    cin >> list_a[i] ;
  vector<int> list_b(length) ;
  for (int i = 0 ; i < length ; i++)
    cin >> list_b[i] ;

  vector< vector<int> > adj_list(2 * length + 2) ;
  adj_list[0].push_back(1) ;
  adj_list[0].push_back(length + 1) ;
  for (int i = 0 ; i < length - 1 ; i++) {
    if ( abs(list_a[i] - list_a[i + 1]) <= upper_bound )
      adj_list[i + 1].push_back(i + 2) ;
    if ( abs(list_a[i] - list_b[i + 1]) <= upper_bound )
      adj_list[i + 1].push_back(length + i + 2) ;
  }
  for (int i = 0 ; i < length - 1 ; i++) {
    if ( abs(list_b[i] - list_a[i + 1]) <= upper_bound )
      adj_list[length + i + 1].push_back(i + 2) ;
    if ( abs(list_b[i] - list_b[i + 1]) <= upper_bound )
      adj_list[length + i + 1].push_back(length + i + 2) ;
  }
  adj_list[length].push_back(2 * length + 1) ;
  adj_list[2 * length].push_back(2 * length + 1) ;

  if (is_reachable_dfs(adj_list, 0, 2 * length + 1))
    cout << "Yes" << endl ;
  else
    cout << "No" << endl ;
}
