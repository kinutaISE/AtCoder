#ifndef RECORD_OPAIVIAO89134_INCLUDED_
#define RECORD_OPAIVIAO89134_INCLUDED_

#include "../functions/functions_str.cpp"
#include "../functions/functions_time.cpp"
#include <string>
#include <vector>

using namespace std ;

enum ATTRIBUTE {
  TICK,
  DIST
} ;

class Record {
private:
  double tick ;
  double distance_diff ;
  double magnification ;
public:
  Record(string line) ;
  double get_tick() const ;
  double get_distance_diff() const ;
  double get_magnification() const ;
} ;

Record::Record(string line) {
  auto data = split(line, ' ') ;
  tick = get_time_from_stamp( data[TICK] ) ;
  distance_diff = stod( data[DIST] ) ;
  magnification = calc_magnification( data[TICK] ) ;
}
double Record::get_tick() const {
  return tick ;
}
double Record::get_distance_diff() const {
  return distance_diff ;
}
double Record::get_magnification() const {
  return magnification ;
}
#endif
