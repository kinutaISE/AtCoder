#include <iostream>
#include <vector>
using namespace std ;

int main() {
  int n ;
  cin >> n ;

  vector<int> data(n) ;
  for (int i = 0; i < n ; i++)
    cin >> data.at(i) ;

  sort(data.begin(), data.end()) ;

  int max_count_num ;
  int max_count = -1 ;
  int start_pos = 0 ;
  int current_num = data.at(start_pos) ;
  int pos = 0 ;

  while (start_pos < n) {
    current_num = data.at(start_pos) ;
    while (data.at(pos) == current_num) {
      pos++ ;
      if (pos == n) break ;
    }
    int count = pos - start_pos ;
    if (max_count < count) {
      max_count = count ;
      max_count_num = current_num ;
    }
    start_pos = pos ;
  }

  cout << max_count_num << ' ' << max_count << endl ;
}
