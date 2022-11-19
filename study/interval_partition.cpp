/*
問：区間 [0, L) を分割するとき，分割された各区間の長さが l_1, l_2, ..., l_n のいずれかで有るものは何通りあるか（L, l_1, l_2, ..., l_n は全て正の整数）
・前提：
  1. l_i <= L (1 <= i <= n)
  2. l_1, l_2, ..., l_n は互いに異なる値
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

int main() ;
void dp() ;
void dp_core(int Lp) ;

// 入力の値を格納する変数
int L, n ;
vector<int> lengths ;

int main() {
  // 入力の受け取り
  cin >> L >> n ;
  lengths = vector<int>(n) ;
  for (int k = 0 ; k < n ; k++)
    cin >> lengths.at(k) ;
  sort(lengths.begin(), lengths.end()) ;
  // 動的計画法の実行
  dp() ;
}
// 以下より，動的計画法の本体 ///////////////////////////////////////////

vector<int64_t> solutions ; // solutions.at(Lp): 区間 [0, Lp) を分割する場合の答え
void dp() {
  /*
  solutions の初期化
  - solutions.at(0) = 1
  - solutions.at(Lp) = -1 (1 <= Lp <= L)
  とする（未計算であることのフラグとして 0 以外の場合を -1 とする）
  */
  solutions = vector<int64_t>(L + 1) ;
  solutions.at(0) = 1 ;
  for (int Lp = 1 ; Lp <= L ; Lp++)
    solutions.at(Lp) = -1 ;
  // 動的計画法
  dp_core(L) ;
  // 答えの出力
  cout << solutions.at(L) << endl ;
}
void dp_core(int Lp) {
  // メモ化再帰により，solutions.at(Lp) を求める関数

  /*
  dp_core(Lp) が終了するまでに，
  Lpp >= Lp となる Lpp について dp_core(Lpp)  は呼び出されないため
  最初に未計算のフラグ(-1)を外す
  */
  solutions.at(Lp) = 0 ;

  // l_1, l_2, ..., l_n の順に右端に配置した場合の数を足し合わせる
  for (int k = 0 ; k < n ; k++) {
    int Lpp = Lp - lengths.at(k) ;
    /*
    lengths.at(k) < lengths.at(k + 1) < ... < lengths.at(n - 1) より，
    Lp - lengths.at(k) > Lp - lengths.at(k + 1) > ... > Lp - lengths.at(n - 1)
    であるため，Lpp < 0 の場合，k + 1 以降も計算する必要がない
    */
    if ( Lpp < 0 )
      break ;
    // solutions.at(Lpp) が未計算かどうか
    if ( solutions.at(Lpp) < 0 )
      dp_core(Lpp) ;
    solutions.at(Lp) += solutions.at(Lpp) ;
  }
}