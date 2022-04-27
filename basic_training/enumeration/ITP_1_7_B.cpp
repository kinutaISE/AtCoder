#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std ;

int n ;
int solution_num ;
int purpose_sum ;
int residual ;

void bt_count_core(int i, int k) {
  // i: 残り何個の数値を選択するのか
  // k: 選択できる範囲の下限（1以上k以下の数値から選択する）
  if (i == 1) {
    if (residual >= 1 && residual <= k)
      solution_num++ ;
    return ;
  }
  int ub = min(residual, k) ;
  for (int kk = ub ; kk >= 1 ; kk--) {
    residual -= kk ;
    bt_count_core(i - 1, kk - 1) ;
    residual += kk ;
  }
}
void bt_count() {
  solution_num = 0 ;
  residual = purpose_sum ;
  bt_count_core(3, n) ;
  cout << solution_num << endl ;
}

vector<int> split_stoi(string str) {
  vector<string> result_str(1) ;
  int pos = 0 ;
  for (char c : str) {
    if (c == ' ') {
      result_str.push_back("") ;
      pos++ ;
      continue ;
    }
    result_str[pos] += c ;
  }
  vector<int> result ;
  for (string str : result_str)
    result.push_back( stoi(str) ) ;
  return result ;
}

int main() {
  while (! cin.eof() ) {
    string line ;
    getline(cin, line) ;
    if (line == "0 0")
      return 0 ;
    auto input = split_stoi(line) ;
    n = input[0] ;
    purpose_sum = input[1] ;
    bt_count() ;
  }
}
