#ifndef DELIVERER_TUAICY0138_INCLUDED_
#define DELIVERER_TUAICY0138_INCLUDED_

#include "../functions/functions_str.cpp"
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

// Deliverer クラス定義 //////////////////////////////////////////////////////////////////
enum STATUS {
  DELIVERING,
  WAITING,
  RESTING
} ;
class Deliverer {
private:
  string id ;
  STATUS status ;
  pair<int, int> location ;
  int sales ;
public:
  Deliverer() ;
  Deliverer(Query q) ;
  string get_id() ;
  bool is_available(Query q) ;
  void set_status(STATUS s) ;
  int get_dist(Query q) ;
  void add_sales(int v) ;
} ;

// Deliverer クラス実装 //////////////////////////////////////////////////////////////////
// コンストラクタ
Deliverer::Deliverer() {
  id = "" ;
  status = WAITING ;
}
Deliverer::Deliverer(Query q) {
  // 前提：q は set_available クエリ
  // YYYY-MM-DD HH:MM set_available 配達員ID x y
  id = q.get_id() ;
  status = WAITING ;
  auto splited_query = split( q.get_body(), ' ' ) ;
  location.first = stoi(splited_query[4]) ;
  location.second = stoi(splited_query[5]) ;
}
string Deliverer::get_id() {
  return id ;
}
bool Deliverer::is_available(Query q) {
  return (status == WAITING) ;
}
void Deliverer::set_status(STATUS s) {
  status = s ;
}
int Deliverer::get_dist(Query q) {
  // 前提：q は order クエリ
  auto splited_query = split( q.get_body(), ' ' ) ;
  pair<int, int> location_q = make_pair(
    stoi( splited_query[5] ),
    stoi( splited_query[6] )
  ) ;
  return abs(location.first - location_q.first) + abs(location.second - location_q.second) ;
}
void Deliverer::add_sales(int v) {
  sales += v ;
}


// DelivererSet クラス定義 //////////////////////////////////////////////////////////////////
class DelivererSet {
private:
  map<string, Deliverer> container ;
public:
  DelivererSet() ;
  void accept_query(Query q) ;
  void add_new_deliverer(Query q) ;
  bool is_available(Query q) ;
  Deliverer get_best_deliverer(Query q) ;
} ;

// DelivererSet クラス実装 //////////////////////////////////////////////////////////////////
DelivererSet::DelivererSet() {}
void DelivererSet::accept_query(Query q) {
  // 前提：q は配達員に関するクエリ
  // set_available クエリの場合
  if (q.get_type() == "set_available") {
    // その配達員が container に存在しない場合
    if (! container.count( q.get_id() ) )
      add_new_deliverer(q) ;
    // その配達員が container に存在する場合
    else
      container.at( q.get_id() ).set_status(WAITING) ;
  }
}
void DelivererSet::add_new_deliverer(Query q) {
  Deliverer deliverer(q) ;
  container[ q.get_id() ] = deliverer ;
}
bool DelivererSet::is_available(Query q) {
  for (auto &s_d : container) {
    Deliverer d = s_d.second ;
    if (d.is_available(q))
      return true ;
  }
  return false ;
}
Deliverer DelivererSet::get_best_deliverer(Query q) {
  Deliverer deliverer ;
  int best_dist = 10000 ;
  for (auto &s_d : container) {
    Deliverer d = s_d.second ;
    if (! d.is_available(q))
      continue ;
    int dist = d.get_dist(q) ;
    if (best_dist <= dist)
      continue ;
    best_dist = dist ;
    deliverer = d ;
  }
  return deliverer ;
}
#endif
