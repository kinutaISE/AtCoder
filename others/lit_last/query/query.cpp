#ifndef QUERY_LPAICIAO8913_INCLUDED_
#define QUERY_LPAICIAO8913_INCLUDED_

#include <string>
#include <queue>

using namespace std ;

// Query クラス定義 //////////////////////////////////////////////////
class Query {
private:
  string body ;
  string tick_ymd ; // 年月日(YY-MM-DD)
  string tick_hm ; // 時分(HH:MM)
  string type ; // クエリの種類
  string id ; // レストランID または 配達員ID
public:
  Query(string line) ;
  string get_body() ;
  string get_tick_ymd() ;
  string get_tick_hm() ;
  string get_type() ;
  string get_id() ;
} ;

// Query クラス実装 //////////////////////////////////////////////////
Query::Query(string line) {
  body = line ;
  auto query_splited = split(line, ' ') ;
  tick_ymd = query_splited[0] ;
  tick_hm = query_splited[1] ;
  type = query_splited[2] ;
  id = query_splited[3] ;
}
string Query::get_body() {
  return body ;
}
string Query::get_tick_ymd() {
  return tick_ymd ;
}
string Query::get_tick_hm() {
  return tick_hm ;
}
string Query::get_type() {
  return type ;
}
string Query::get_id() {
  return id ;
}

// QueryQueue クラス定義 //////////////////////////////////////////////////
class QueryQueue {
private:
  queue<Query> container ;
public:
  QueryQueue() ;
  void initialize(vector<string> lines) ;
  Query front() ; // 先頭のアクセスを得る
  void pop() ; // 先頭を削除する
  bool empty() ; // container が空かどうか
} ;

// QueryQueue クラス実装 //////////////////////////////////////////////////
// コンストラクタ
QueryQueue::QueryQueue() {}
// 初期化
void QueryQueue::initialize(vector<string> lines) {
  int resutaurant_num = stoi(lines[0]) ;
  for (int i = resutaurant_num + 1 ; i < lines.size() ; i++) {
    Query query(lines[i]) ;
    container.push(query) ;
  }
}
// 先頭のアクセスを得る
Query QueryQueue::front() {
  return container.front() ;
}
// 先頭を削除する
void QueryQueue::pop() {
  container.pop() ;
}
// 空かどうかを返す
bool QueryQueue::empty() {
  return container.empty() ;
}

#endif
