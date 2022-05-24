#ifndef RESTAURANT_NIACOA89194_INCLUDED_
#define RESTAURANT_NIACOA89194_INCLUDED_

#include "../functions/functions_str.cpp"
#include "../functions/functions_time.cpp"
#include "../query/query.cpp"
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std ;

// Restaurant クラス定義 //////////////////////////////////////////////////////////
class Restaurant {
private:
  string id ;
  pair<int, int> location ;
  vector< pair<int, int> > closed_times ;
  int sales ;
public:
  Restaurant() ;
  Restaurant(vector<string> data) ;
  string get_id() ;
  bool is_opening(Query q) ;
  void add_sales(int v) ;
} ;

// Restaurant クラス実装 //////////////////////////////////////////////////////////
Restaurant::Restaurant() {}
Restaurant::Restaurant(vector<string> data) {
  // レストランID
  id = data[0] ;
  // 位置
  location.first = stoi(data[1]) ;
  location.second = stoi(data[2]) ;
  // 休業時間
  for (int i = 3 ; i < data.size() ; i++) {
    auto time_window = split(data[i], '-') ;
    pair<int, int> closed_time(get_minutes_from_stamp_hm(time_window[0]),
    get_minutes_from_stamp_hm(time_window[1])) ;
    closed_times.push_back(closed_time) ;
  }
}

string Restaurant::get_id() {
  return id ;
}

bool Restaurant::is_opening(Query q) {
  int minute = get_minutes_from_stamp_hm( q.get_tick_hm() ) ;
  for (auto ct : closed_times) {
    if (minute >= ct.first && minute < ct.second)
      return false ;
  }
  return true ;
}

void Restaurant::add_sales(int v) {
  sales += v ;
}

// RestaurantSet クラス定義 //////////////////////////////////////////////////////////
class RestaurantSet {
private:
  int resutaurant_num ;
  map<string, Restaurant> container ;
public:
  RestaurantSet() ;
  void initialize(vector<string> lines) ;
  Restaurant get(string id) ;
  bool is_opening(Query q) ;
} ;

// RestaurantSet クラス実装 //////////////////////////////////////////////////////////
// コンストラクタ
RestaurantSet::RestaurantSet() {
  resutaurant_num = 0 ;
}
void RestaurantSet::initialize(vector<string> lines) {
  // レストラン数
  resutaurant_num = stoi(lines[0]) ;
  // 2行目から resutaurant_num 行目まで元に初期化
  for (int i = 1 ; i <= resutaurant_num ; i++) {
    auto data = split(lines[i], ' ') ;
    Restaurant resutaurant(data) ;
    container[ data[0] ] = resutaurant ;
  }
}
Restaurant RestaurantSet::get(string id) {
  return container.at(id) ;
}
bool RestaurantSet::is_opening(Query q) {
  return container.at( q.get_id() ).is_opening(q) ;
}

#endif
