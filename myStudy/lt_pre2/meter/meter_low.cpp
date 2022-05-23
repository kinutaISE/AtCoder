#ifndef METER_LOW_IAICOA8914_INCLUDED_
#define METER_LOW_IAICOA8914_INCLUDED_

#include "../base_info.h"
#include "../record/record.cpp"

using namespace std ;

const int SWITCHING_SEC = 45 ;

// 定義 //////////////////////////////////////////////////
class LowSpeedMeter {
private:
  double time_total ;
  int next_switch ;
public:
  LowSpeedMeter() ;
  int get_interval_num() ;
  bool update(double time_diff) ;
} ;

// 実装 //////////////////////////////////////////////////
// コンストラクタ
LowSpeedMeter::LowSpeedMeter() {
  time_total = 0.0 ;
  next_switch = SWITCHING_SEC ;
}

// 低速走行メーターを更新する関数
// 前提：受け取るレコードは平均速度が10km/h以下
// 低速走行区間をまたいだ場合、trueを返す
bool LowSpeedMeter::update(double time_diff) {
  time_total += time_diff ;
  if (time_total < next_switch)
    return false ;
  next_switch += SWITCHING_SEC ;
  return true ;
}

#endif
