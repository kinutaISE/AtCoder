#ifndef FUNCTION_TIME_AISOA8913_INCLUDED_
#define FUNCTION_TIME_AISOA8913_INCLUDED_

#include "../base_info.h"
#include "functions_str.cpp"

// 定義 /////////////////////////////////////////////////////////
double get_time_from_stamp(const string stamp) const ;
double hour_to_sec(const double h) const ;
double minute_to_sec(const double m) const ;
MAGNIFICATION get_magnification(const string stamp) const ;
bool is_midnight(const int t_24) const ;
bool is_peaktime(const int t_24) const ;

// 実装 //////////////////////////////////////////////////////////
enum TIME {
  HOUR, MINUTE, SECOND
}
double get_time_from_stamp(const string stamp) const {
  auto stamp_splited = split(stamp, ':') ;
  double hour = stod( stamp_splited[HOUR] ) ;
  double minute = stod( stamp_splited[MINUTE] ) ;
  double seconds = stod( stamp_splited[SECOND] ) ;
  return hour_to_sec(hour) + minute_to_sec(minute) + seconds ;
}
double hour_to_sec(const double h) const {
  return h * 24.0 * 60.0 ;
}
double minute_to_sec(const double m) const {
  return m * 60.0 ;
}
MAGNIFICATION get_magnification(const string stamp) const {
  int time_24 = get_time_from_stamp(stamp) % (24 * 60 * 60) ;
  return is_midnight(time_24) ? MIDNIGHT :
    is_peaktime(time_24) ? PEAKTIME : STANDARD ;
}
bool is_midnight(const int t_24) const {
  return (t_24 >= time_separations["MIDNIGHT"]["START"]
    && t_24 < time_separations["MIDNIGHT"]["FINISH"]) ;
}
bool is_peaktime(const int t_24) const {
  return
  (t_24 >= time_separations["PEAKTIME_MORNING"]["START"]
    && t_24 < time_separations["PEAKTIME_MORNING"]["FINISH"]) ||
  (t_24 >= time_separations["PEAKTIME_NIGHT"]["START"]
    && t_24 < time_separations["PEAKTIME_NIGHT"]["FINISH"]) ;
}

#endif
