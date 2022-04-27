#include <iostream>
#include <vector>
using namespace std;

int N ;
int bound ; // K

int best_size ;

int get_evaluation(vector<bool> table) {
  int size = 0 ;
  int index = -1 ;
  while (index < N - 1) {
    index++ ;
    if (! table.at(index))
      continue ;
    int count = 1 ;
    for (index = index + 1 ; index < N ; index++) {
      if (! table.at(index))
        break ;
      count++ ;
    }
    size = max(size, count) ;
  }
  return size ;
}
void backtracking(int k, int r, vector<bool> table) {
  if (k == N || r == 0) {
    //best_size = max(best_size, get_evaluation()) ;
    int eval = get_evaluation() ;
    if (best_size < eval) {
      best_size = eval ;
      cout << "update" << endl ;
      for (bool b : table)
        cout << b << ' ' ;
      cout << endl ;
    }
    return ;
  }
  backtracking(k + 1, r, table) ;
  if (table.at(k))
    return ;
  table.at(k) = true ;
  backtracking(k + 1, r - 1, table) ;
}
void backtracking(string s) {
  N = s.size() ;
  vector<bool> table(N) ;
  for (char c : s)
    table.push_back( c == 'X' ) ;
  best_size = 0 ;
  backtracking(0, bound, table) ;
}

int main() {
  string s ;
  cin >> s ;
  cin >> bound ;

  backtracking(s) ;

  cout << best_size << endl ;
}
