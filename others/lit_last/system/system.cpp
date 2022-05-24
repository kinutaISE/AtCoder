#ifndef SYSTEM_EACIAO89349_INCLUDED_
#define SYSTEM_EACIAO89349_INCLUDED_

#include "../restaurant/restaurant.cpp"
#include "../deliverer/deliverer.cpp"
#include "../query/query.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std ;

// 定義 //////////////////////////////////////////////////////////
class DeliverySystem {
private:
  RestaurantSet restaurants ;
  DelivererSet deliverers ;
  QueryQueue queries ;
public:
  DeliverySystem(vector<string> lines) ;
  void process_top_query() ;
  bool is_completed() ;
  void process_order_query(Query q) ;
  void process_set_available_query(Query q) ;
} ;

// 実装 //////////////////////////////////////////////////////////
// コンストラクタ
DeliverySystem::DeliverySystem(vector<string> lines) {
  restaurants.initialize(lines) ;
  queries.initialize(lines) ;
}
void DeliverySystem::process_top_query() {
  Query query = queries.front() ;
  string query_type = query.get_type() ;

  // orderクエリの場合
  if (query_type == "order")
    process_order_query(query) ;
  // set_availableクエリの場合
  if (query_type == "set_available") {
    process_set_available_query(query) ;
  }
  queries.pop() ;
}
void DeliverySystem::process_order_query(Query q) {
  // レストランが休業時間であるかどうか
  // 休業中であれば、"ERROR CLOSED TIME" と出力
  if (! restaurants.is_opening(q) )
    cout << "ERROR CLOSED TIME" << endl ;

  // 配達員を選ぶことができるかどうか
  // できなければ、"ERROR NO DELIVERY PERSON" と出力
  else if (! deliverers.is_available(q) )
    cout << "ERROR NO DELIVERY PERSON" << endl ;

  // 注文を受理する
  else {
    // 1. 配達員を選択する
    auto deliverer = deliverers.get_best_deliverer(q) ;
    // 2. 配達員の送料を計算する
    int dist = deliverer.get_dist(q) ;
    int postage =
      (dist < 100) ? 300 :
      (dist < 1000) ? 600 :
      (dist < 10000) ? 900 : 1200 ;
    // 3. 配達員の売り上げに送料を加算する
    deliverer.add_sales(postage) ;
    // 4. レストランの売り上げに記録をつける
    auto splited_query = split(q.get_body(), ' ') ;
    int payment = stoi(splited_query[4]) ;
    restaurants.get( q.get_id() ).add_sales(payment - postage) ;

    cout << q.get_tick_ymd() << " " << q.get_tick_hm() << " " << deliverer.get_id() << " " << postage << endl ;
  }
}
void DeliverySystem::process_set_available_query(Query q) {
  deliverers.accept_query(q) ;
}
// 全てのクエリが完了したかどうかを返す関数
bool DeliverySystem::is_completed() {
  return queries.empty() ;
}

#endif
