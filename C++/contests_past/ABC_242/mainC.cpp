#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std ;

int64_t count ;
int source ;
int sink ;
void bt_count(vector<int> &adj_list, int u) {
  if (u == t) {

  }
}
void bt_count(vector<int> &adj_list, int s, int t) {
  source = s ;
  sink = t ;
  bt_count(adj_list, s) ;
}

int main() {
  int digit_num ;
  cin >> digit_num ;

  vector< vector<int> > adj_list(9 * digit_num + 2) ;
  for (int i = 1 ; i <= 9 ; i++)
    adj_list[0].push_back(i) ;
  for (int d = 0 ; d < digit_num - 1 ; d++) {
    for (int i = 1 ; i <= 9 ; i++) {
      for (int j = max(1, i - 1) ; j <= min(9, i + 1) ; j++)
        adj_list[9 * d + i].push_back(9 * (d + 1) + j) ;
    }
  }
  for (int i = 1 ; i <= 9 ; i++)
    adj_list[9 * (digit_num - 1) + i].push_back(9 * digit_num + 1) ;


  for (int u = 0 ; u < 9 * digit_num + 2 ; u++) {
    cout << "adj_list[" << u << "] : " ;
    for (int v : adj_list[u])
      cout << v << " " ;
    cout << endl ;
  }

  cout << count_dfs(adj_list, 0, 9 * digit_num + 1) % 998244353 << endl ;
}
