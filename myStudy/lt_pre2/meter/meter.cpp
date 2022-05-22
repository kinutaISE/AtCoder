#include "../record/record.cpp"

// 定義 //////////////////////////////////////////////////////////////////
class Meters {
private:
  double time ;
  double distance_total ;
  double fare ;
public:
  Meters() ;
  void update(const Record &record) const ;
  bool is_low_speed(const Record &record) const ;
  double calculate_spped(const Record &record) const ;
} ;

// 実装 //////////////////////////////////////////////////////////////////
Meters::Meters() {
  time = 0.0 ;
  distance_total = 0.0 ;
  fare = 0.0 ;
}
void Meters::update(const Record &record) const {
  if ( is_low_speed(record) )

}
bool is_low_speed(const Record &record) const {
  return calculate_spped(record) <= 36000 ;
}
double calculate_spped(const Record &record) const {
  return record.get_distance_diff() / ( time - record.get_time() ) ;
}
