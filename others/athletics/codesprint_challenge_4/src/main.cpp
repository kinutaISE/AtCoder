#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std ;

// 関数の定義 //////////////////////////////////////////////

// 入力を受け取り、nums に各桁の値を代入する
void accept_input(vector<int> &nums) ;

// char型の数字を int 型の数値として返す関数
int ctoi(const char c) ;

// 最小の数値となるように並び替える関数
void arrange_to_min_number(vector<int> &nums) ;

// 格納されている数値を先頭から繋げて表示する関数
void show_number(const vector<int> &nums) ;

///////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
  // 入力を numbers に格納
  vector<int> numbers ;
  accept_input(numbers) ;

  // 答えとなる並び順を numbers に格納
  arrange_to_min_number(numbers) ;

  // 答えを表示
  show_number(numbers) ;

  return 0;
}

// 関数の実装 //////////////////////////////////////////////////
// 入力を受け取り、nums に各桁の値を代入する
void accept_input(vector<int> &nums) {
  string num_str ;
  cin >> num_str ;

  for (const char c : num_str)
    nums.push_back( ctoi(c) ) ;
}

// char型の数字を int 型の数値として返す関数
int ctoi(const char c) {
  return c - '0' ;
}

// 最小の数値となるように並び替える関数
void arrange_to_min_number(vector<int> &nums) {
  // 昇順にソートする
  sort(nums.begin(), nums.end()) ;

  // 先頭が 0 でない場合は終了
  if ( *nums.begin() ) return ;

  // 先頭が 0 の場合の処理
  auto itr = nums.begin() ;
  while ( ! *itr ) itr++ ;
  swap(*nums.begin(), *itr) ;
}

// 格納されている数値を先頭から繋げて表示する関数
void show_number(const vector<int> &nums) {
  for (int v : nums)
    cout << v ;
  cout << endl ;
}
