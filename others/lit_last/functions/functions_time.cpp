#ifndef FUNCTION_TIME_AISOA8913_INCLUDED_
#define FUNCTION_TIME_AISOA8913_INCLUDED_

#include "../base_info.h"
#include "functions_str.cpp"
#include <cmath>
#include <string>

using namespace std ;

// 定義 /////////////////////////////////////////////////////////
int get_minutes_from_stamp_hm(string stamp) ;
int hour_to_min(int h) ;

// 実装 //////////////////////////////////////////////////////////
int get_minutes_from_stamp_hm(string stamp) {
  // stamp は HH:MM の形式で渡される
  auto stamp_splited = split(stamp, ':') ;
  int hour = stoi( stamp_splited[0] ) ;
  int minute = stoi( stamp_splited[1] ) ;
  return hour_to_min(hour) + minute ;
}
int hour_to_min(int h) {
  return h * 24 ;
}

#endif
