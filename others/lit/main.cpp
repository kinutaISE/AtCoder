#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std ;

int town_width, house_num, load_width ;
/*
  town_width: 街の幅
  house_num: 家の件数
  load_width: 道の幅
*/
vector< vector<int64_t> > values ;
/*
  各区画に含まれる家の価値
  - values[x][y]は x_i = x, y_i = y となる家の価値の総和を表す
*/

vector<int64_t> values_horizontal ;
vector<int64_t> values_vertical ;
vector< vector<int64_t> > values_square ;
int64_t calc_value(int x, int y, int rx, int ry) {
  /*
  values[x][y] ~ values[x + rx - 1][y + ry - 1] の範囲に含まれる家の価値の合計を求める
  */
  int64_t value = 0 ;
  for (int dx = 0 ; dx < rx ; dx++) {
    for (int dy = 0 ; dy < ry ; dy++)
      value += values[x + dx][y + dy] ;
  }
  return value ;
}

void set_values_horizontal() {
  values_horizontal = vector<int64_t>(town_width - load_width + 1) ;
  for (int y = 0 ; y <= town_width - load_width ; y++)
    values_horizontal[y] = calc_value(0, y, town_width, load_width) ;
}
void set_values_vertical() {
  values_vertical = vector<int64_t>(town_width - load_width + 1) ;
  for (int x = 0 ; x <= town_width - load_width ; x++)
    values_vertical[x] = calc_value(x, 0, load_width, town_width) ;
}
void set_values_square() {
  values_square = vector< vector<int64_t> >(town_width - load_width + 1, vector<int64_t>(town_width - load_width + 1)) ;
  for (int x = 0 ; x <= town_width - load_width ; x++) {
    for (int y = 0 ; y <= town_width - load_width ; y++)
      values_square[x][y] = calc_value(x, y, load_width, load_width) ;
  }
}
void set_values() {
  set_values_horizontal() ;
  set_values_vertical() ;
  set_values_square() ;
}

int64_t calc_cost(int x, int y) {
  return values_horizontal[y] + values_vertical[x] - values_square[x][y] ;
}

int main(int argc, char* argv[]) {
  cin >> town_width >> house_num >> load_width ;
  values = vector< vector<int64_t> >( town_width, vector<int64_t>(town_width) ) ;
  int64_t upper_bound = 0 ;
  for (int i = 0 ; i < house_num ; i++) {
    int x, y ;
    int64_t v ;
    cin >> x >> y >> v ;
    values[x][y] += v ;
    upper_bound += v ;
  }

  set_values() ;

  int64_t min_cost = upper_bound ;
  int range = town_width - load_width ;
  for (int x = 0 ; x <= range ; x++) {
    for (int y = 0 ; y <= range ; y++)
      min_cost = min(min_cost, calc_cost(x, y) ) ;
  }

  cout << min_cost << endl ;
}
