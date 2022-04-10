#include <iostream>
#include <vector>

using namespace std ;

int find_pos(vector<int> list, int k) {
  for (int  i = 0; i < list.size(); i++)
    if (list[i] == k) return i ;
  return -1 ;
}

int main() {
  int n ;
  cin >> n ;
  vector<int> residuals(2 * n + 1) ;
  for (int k = 0 ; k < 2 * n + 1 ; k++)
    residuals[k] = k + 1 ;

  cout << residuals[0] << endl ;
  residuals.erase(residuals.begin()) ;
  int aoki_num ;
  cin >> aoki_num ;
  while (aoki_num != 0) {
    int pos = find_pos(residuals, aoki_num) ;
    residuals.erase(residuals.begin() + pos) ;
    cout << residuals[0] << endl ;
    residuals.erase(residuals.begin()) ;
    cin >> aoki_num ;
  }
}
