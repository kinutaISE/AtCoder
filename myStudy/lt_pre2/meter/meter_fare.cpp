#ifndef METER_FARE_IAOCOAIE8914_INCLUDED_
#define METER_FARE_IAOCOAIE8914_INCLUDED_

#include "../base_info.h"
#include "../record/record.cpp"

using namespace std ;

// 定義 //////////////////////////////////////////////////////////
class FareMeter {
private:
  int fare_total ;
public:
  FareMeter() ;
  void update_low(const Record &record) ;
  void update_dist(const Record &record) ;
  int get_fare() const ;
} ;

// 実装 //////////////////////////////////////////////////////////
// コンストラクタ
FareMeter::FareMeter() {
  fare_total = 400 ;
}
// 低速走行メーターの更新に伴う更新
void FareMeter::update_low(const Record &record) {
  fare_total += (int)40.0 * record.get_magnification() ;
}
void FareMeter::update_dist(const Record &record) {
  fare_total += (int)40.0 * record.get_magnification() ;
}
int FareMeter::get_fare() const {
  return fare_total ;
}

#endif
