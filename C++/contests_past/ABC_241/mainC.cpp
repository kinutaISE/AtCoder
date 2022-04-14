#include <iostream>
#include <vector>

using namespace std ;
int N ;
vector< vector<bool> > matrix ;

bool is_feasible(int row, int col) {
  int sum = 0 ;
  // 横方向
  for (int i = row ; i < row + 6 ; i++) {
    sum = 0 ;
    for (int j = col ; j < col + 6 ; j++)
      sum += matrix[i][j] ;
    if (sum >= 4) return true ;
  }
  // 縦方向
  for (int j = col ; j < col + 6 ; j++) {
    sum = 0 ;
    for (int i = row  ; i < row + 6 ; i++)
      sum += matrix[i][j] ;
    if (sum >= 4) return true ;
  }
  // 斜め方向
  sum = 0 ;
  for (int k = 0 ; k < 6 ; k++)
    sum += matrix[row + k][col + k] ;
  if (sum >= 4) return true ;

  sum = 0 ;
  for (int k = 0 ; k < 6 ; k++)
    sum += matrix[row + 5 - k][col + k] ;
  if (sum >= 4) return true ;

  return false ;
}
bool is_feasible() {
  for (int i = 0 ; i <= N - 6 ; i++) {
    for (int j = 0 ; j <= N - 6 ; j++)
      if (is_feasible(i, j)) return true ;
  }
  return false ;
}

int main() {
  cin >> N ;
  matrix = vector< vector<bool> > (N, vector<bool>(N)) ;
  for (int i = 0 ; i < N ; i++) {
    string line ;
    cin >> line ;
    for (int j = 0 ; j < N ; j++)
      matrix[i][j] = (line[j] == '#') ? 1 : 0 ;
  }

  if (is_feasible())
    cout << "Yes" << endl ;
  else
    cout << "No" << endl ;
}
