#include <iostream>
#include <vector>
using namespace std ;

vector< vector<char> > getInitializedTable(int N) {
  vector< vector<char> > table( N, vector<char>(N) ) ;
  for (int i = 0; i < N; i++) {
    for (int j = 0 ; j < N ; j++)
      table.at(i).at(j) = '-' ;
  }
  return table ;
}

void recordMatchResults(vector< vector<char> > &table, vector<int> winners, vector<int> losers) {
  int M = winners.size() ;
  for (int k = 0 ; k < M ; k++) {
    int winner = winners.at(k) - 1 ;
    int loser = losers.at(k) - 1 ;
    table.at(winner).at(loser) = 'o' ;
    table.at(loser).at(winner) = 'x' ;
  }
}

void showTable(vector< vector<char> > table) {
  /* 行の最後に ' ' が入ってしまっていると，誤りと判定されるので注意 */
  int N = table.size() ;
  for (int i = 0 ; i < N ; i++) {
    for (int j = 0 ; j < N - 1 ; j++)
      cout << table.at(i).at(j) << ' ' ;
    cout << table.at(i).at(N - 1) << endl ;
  }
  /*
  for (vector<char> row : table) {
    for (char res : row)
      cout << res << ' ' ;
    cout << endl ;
  }
  */
}

int main() {
  int N, M ;
  cin >> N >> M ;
  vector<int> A(M), B(M) ;
  for (int i = 0; i < M; i++)
    cin >> A.at(i) >> B.at(i) ;

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector< vector<char> > table = getInitializedTable(N) ;
  recordMatchResults(table, A, B) ;
  showTable(table) ;
}
