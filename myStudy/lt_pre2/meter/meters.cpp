#include "../record/record.cpp"
#include "meter_low.cpp"
#include "meter_fare.cpp"
#include "distance_meter.cpp"


using namespace std ;

// 定義 //////////////////////////////////////////////////////////////////
class Meters {
private:
  double last_tick ;
  DistanceMeter meter_dist ;
  LowSpeedMeter meter_low ;
  FareMeter meter_fare ;
public:
  Meters() ;
  void initialize(const Record &record) ;
  void update(const Record &record) ;
  bool is_low_speed(const Record &record) const ;
  double calculate_spped(const Record &record) const ;
  int get_total_fare() const ;
} ;

// 実装 //////////////////////////////////////////////////////////////////
Meters::Meters() {
  last_tick = 0.0 ;
}
void Meters::initialize(const Record &record) {
  last_tick = record.get_tick() ;
}
void Meters::update(const Record &record) {
  double time_diff = record.get_tick() - last_tick ;
  if ( is_low_speed(record) ) {
    if ( meter_low.update(time_diff) )
      meter_fare.update_low(record) ;
  }
  if ( meter_dist.update(record) )
    meter_fare.update_dist(record) ;
  last_tick += time_diff ;
}
bool Meters::is_low_speed(const Record &record) const {
  return calculate_spped(record) <= 36000 ;
}
double Meters::calculate_spped(const Record &record) const {
  return record.get_distance_diff() / ( last_tick - record.get_tick() ) ;
}
int Meters::get_total_fare() const {
  return meter_fare.get_fare() ;
}
