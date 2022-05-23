#ifndef FUNCTION_TIME_AISOA8913_INCLUDED_
#define FUNCTION_TIME_AISOA8913_INCLUDED_

#include "../base_info.h"
#include "functions_str.cpp"
#include <cmath>

// 定義 /////////////////////////////////////////////////////////
double get_time_from_stamp(const string stamp) ;
double hour_to_sec(const double h) ;
double minute_to_sec(const double m) ;
double calc_magnification(const string stamp) ;
bool is_midnight(const int t_24) ;
bool is_peaktime(const int t_24) ;

// 実装 //////////////////////////////////////////////////////////
enum TIME {
  HOUR, MINUTE, SECOND
} ;
double get_time_from_stamp(const string stamp) {
  auto stamp_splited = split(stamp, ':') ;
  double hour = stod( stamp_splited[HOUR] ) ;
  double minute = stod( stamp_splited[MINUTE] ) ;
  double seconds = stod( stamp_splited[SECOND] ) ;
  return hour_to_sec(hour) + minute_to_sec(minute) + seconds ;
}
double hour_to_sec(const double h) {
  return h * 24.0 * 60.0 ;
}
double minute_to_sec(const double m) {
  return m * 60.0 ;
}
double calc_magnification(const string stamp) {
  double time_24 = fmod(get_time_from_stamp(stamp), 24.0 * 60 * 60) ;
  return is_midnight(time_24) ? MIDNIGHT :
    is_peaktime(time_24) ? PEAKTIME : STANDARD ;
}
bool is_midnight(const int t_24) {
  return (t_24 >= time_separations.at("MIDNIGHT_START")
    && t_24 < time_separations.at("MIDNIGHT_FINISH")) ;
}
bool is_peaktime(const int t_24) {
  return
  (t_24 >= time_separations.at("PEAKTIME_MORNING_START")
    && t_24 < time_separations.at("PEAKTIME_MORNING_FINISH")) ||
  (t_24 >= time_separations.at("PEAKTIME_NIGHT_START")
    && t_24 < time_separations.at("PEAKTIME_NIGHT_FINISH")) ;
}

#endif
