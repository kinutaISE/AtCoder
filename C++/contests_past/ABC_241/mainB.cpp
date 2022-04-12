#include <iostream>
#include <vector>

using namespace std ;

int find_pos(vector<int> list, int v) {
  int pos = -1 ;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != v) continue ;
    pos = i ;
    break ;
  }
  return pos ;
}
int main() {
  int noodle_num, days ;
  cin >> noodle_num >> days ;
  vector<int> noodle_length(noodle_num) ;
  for (int i = 0 ; i < noodle_num ; i++)
    cin >> noodle_length[i] ;
  vector<int> eating_length(days) ;
  for (int i = 0 ; i < days ; i++)
    cin >> eating_length[i] ;

  for (int i = 0 ; i < days ; i++) {
    int pos = find_pos(noodle_length, eating_length[i]) ;
    if (pos == -1) {
      cout << "No" << endl ;
      return 0 ;
    }
    noodle_length[pos] = -1 ;
  }
  cout << "Yes" << endl ;
}
