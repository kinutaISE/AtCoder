#ifndef DIST_METER_AIOCAO9138_INCLUDED_
#define DIST_METER_AIOCAO9138_INCLUDED_

#include "../base_info.h"
#include "../record/record.cpp"

using namespace std ;

// 定義 //////////////////////////////////////////////////////////
class DistanceMeter {
private:
  double distance_total ;
  int next_switch ;
public:
  DistanceMeter() ;
  double get_distance_total() const ;
  bool update(const Record &record) ;
  bool is_short_interval() const ;
} ;


// 実装 //////////////////////////////////////////////////////////
DistanceMeter::DistanceMeter() {
  distance_total = 0.0 ;
  next_switch = 1000 ;
}
double DistanceMeter::get_distance_total() const {
  return distance_total ;
}
bool DistanceMeter::update(const Record &record) {
  distance_total += record.get_distance_diff() ;
  if ( distance_total < next_switch )
    return false ;
  next_switch += is_short_interval() ? 400 : 350 ;
  return true ;
}
// 短距離区間であるかどうかを返す関数
bool DistanceMeter::is_short_interval() const {
  return (distance_total > 1000) && (distance_total <= 10200) ;
}

#endif
