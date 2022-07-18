#include <iostream>
#include <vector>

using namespace std ;

int64_t jewel_level ; // 最初に持っている赤い宝石のレベル
int64_t change_from_red ; // 赤い宝石を交換することで得られる青い宝石の数
int64_t change_from_blue ; // 赤い宝石を交換することで得られる赤い宝石の数

vector<int64_t> red ;
vector<int64_t> blue ;
void dp() ;
void dp_red(int lv) ;
void dp_blue(int lv) ;

int main() {
  // 入力の受け取り
  cin >> jewel_level >> change_from_red >> change_from_blue ;
  // 本体
  dp() ;
  cout << red.at(jewel_level) << endl ;
  return 0 ;
}
void dp() {
  for (int i = 0 ; i < jewel_level + 1 ; i++) {
    red.push_back(-1) ;
    blue.push_back(-1) ;
  }
  dp_red(jewel_level) ;
}
void dp_red(int lv) {
  if (lv <= 1) {
    red.at(lv) = 0 ;
    return ;
  }
  if (red.at(lv - 1) == -1)
    dp_red(lv - 1) ;
  if (blue.at(lv) == -1)
    dp_blue(lv) ;
  red.at(lv) = red.at(lv - 1) + change_from_red * blue.at(lv) ;
}
void dp_blue(int lv) {
  if (lv <= 1) {
    blue.at(lv) = lv ;
    return ;
  }
  if (red.at(lv - 1) == -1)
    dp_red(lv - 1) ;
  if (blue.at(lv - 1) == -1)
    dp_blue(lv - 1) ;
  blue.at(lv) = red.at(lv - 1) + change_from_blue * blue.at(lv - 1) ; 
}