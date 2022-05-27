#include <iostream>
#include <vector>

using namespace std ;

const int INPUT = 1000 ;

// フィボナッチ数列の各項を保存するベクトル
vector<int> values(INPUT + 1) ;

// 関数の定義
void initialize() ;
void calc_fib(int n) ;

int main() {
  initialize() ;
  calc_fib(INPUT) ;
  cout << values[INPUT] << endl ;
  return 0 ;
}

// 関数の実装
void initialize() {
  for (int i = 3 ; i <= INPUT ; i++)
    values[i] = -1 ;
  values[1] = values[2] = 1 ;
}
void calc_fib(int n) {
  if (n <= 2)
    return ;
  if (values[n - 1] == -1)
    calc_fib(n - 1) ;
  if (values[n - 2] == -1)
    calc_fib(n - 2) ;
  values[n] = values[n - 1] + values[n - 2] ;
}
