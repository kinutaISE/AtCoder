#include <iostream>
#include <vector>
using namespace std ;

int N, M ;
vector< vector<int> > matrix ;

vector<int> row_sums ;
vector<int> column_sums ;

void set_row_sums() {
  row_sums = vector<int>(N) ;
  for (int i = 0 ; i < N ; i++) {
    vector<int> &matrix_i = matrix.at(i) ;
    int &sum_i = row_sums.at(i) ;
    for (int j = 0 ; j < M ; j++)
      sum_i += matrix_i.at(j) ;
  }
}
void set_column_sums() {
  column_sums = vector<int>(M) ;
  for (int j = 0 ; j < M ; j++) {
    int &sum_j = column_sums.at(j) ;
    for (int i = 0 ; i < N ; i++)
      sum_j += matrix.at(i).at(j) ;
  }
}

int calculate_cross_sum(int r, int c) {
  return row_sums.at(r) + column_sums.at(c) - matrix.at(r).at(c) ;
}

int main() {
  cin >> N >> M ;
  matrix = vector< vector<int> >(N, vector<int>(M)) ;
  for (int i = 0 ; i < N ; i++) {
    vector<int> &matrix_i = matrix.at(i) ;
    for (int j = 0 ; j < M ; j++)
      cin >> matrix_i.at(j) ;
  }

  set_row_sums() ;
  set_column_sums() ;

  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < M - 1 ; j++)
      cout << calculate_cross_sum(i, j) << ' ' ;
    cout << calculate_cross_sum(i, M - 1) << endl ;
  }
}
