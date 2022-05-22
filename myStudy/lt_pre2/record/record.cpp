#ifndef RECORD_OPAIVIAO89134_INCLUDED_
#define RECORD_OPAIVIAO89134_INCLUDED_

#include "../functions/functions_str"
#include "../functions/functions_time"
#include <string>
#include <vector>

using namespace std ;

enum ATTRIBUTE {
  TIME,
  distance_diff
}

class Record {
private:
  double time ;
  double distance_diff ;
  MAGNIFICATION magnification ;
public:
  Record(string line) ;
  double get_time() const ;
  double get_distance_diff() const ;
  MAGNIFICATION get_magnification() const ;
} ;

Record::Record(string line) {
  auto data = split(line) ;
  time = get_time_from_stamp( data[TIME] ) ;
  distance_diff = stod( data[distance_diff] ) ;
  magnification = get_magnification( data[TIME] ) ;
}
double get_time() const {
  return time ;
}
double get_distance_diff() const {
  return distance_diff ;
}
double get_magnification() const {
  return magnification ;
}
#endif
