#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int str_length ;
string str ;

const string ATCODER = "atcoder" ;

/* 動的計画法

  dp[i][k]: str の i 番目までで，atcoder の k 番目までの部分文字列を何通り作れるのか

  ・dp[0][k] := 0
  ・dp[i][k] は i 番目を用いない場合と i 番目を用いる場合の合計
  　dp[i][k] := dp[i - 1][k] + dp[i - 1][k - 1]

*/

vector< vector<int> > table ;

void memoized_recursion_core(int i, int k) {
  if (k == 0) {
    table.at(i).at(0) = 1 ;
    return ;
  }
  if (i < k) {
    table.at(0).at(k) = 0 ;
    return ;
  }

  int ip = i - 1 ;

  int unused_num = table.at(ip).at(k) ; // i 番目の文字を用いない場合の総数
  if (unused_num == -1) {
    memoized_recursion_core(ip, k) ;
    unused_num = table.at(ip).at(k) ;
  }
  table.at(i).at(k) = unused_num ;

  int kp = k - 1 ;
  if (str.at(ip) != ATCODER.at(kp))
    return ;

  int used_num = table.at(ip).at(kp) ;
  if (used_num == -1) {
    memoized_recursion_core(ip, kp) ;
    used_num = table.at(ip).at(kp) ;
  }
  table.at(i).at(k) += used_num ;
}
void memoized_recursion() {
  table = vector< vector<int> >( str_length + 1, vector<int>(ATCODER.size() + 1) ) ;
  for (int i = 0 ; i <= str_length ; i++) {
    for (int k = 0 ; k <= ATCODER.size() ; k++)
      table.at(i).at(k) = -1 ;
  }
  memoized_recursion_core(str_length, ATCODER.size()) ;
}

int main() {
  cin >> str_length ;
  cin >> str ;

  memoized_recursion() ;

  cout << table.at(str_length).at(ATCODER.size()) << endl ;

  return 0 ;
}
