#ifndef BASE_INFO_H_ECIAOEI89138_INCLUDED_
#define BASE_INFO_H_ECIAOEI89138_INCLUDED_

#include <iostream>
#include <string>
#include <map>

using namespace std ;

const map<string, double> time_separations = {
  {"MIDNIGHT_START", 0.0},
  {"MIDNIGHT_FINISH", 6.0 * 24 * 60},
  {"PEAKTIME_MORNING_START", 6.0 * 24 * 60},
  {"PEAKTIME_MORNING_FINISH", 9.0 * 24 * 60 + 30 * 60},
  {"STANDARD_START", 9.0 * 24 * 60 + 30 * 60},
  {"STANDARD_FINISH", 18.0 * 24 * 60},
  {"PEAKTIME_NIGHT_START", 18.0 * 24},
  {"PEAKTIME_NIGHT_FINISH", 24.0 * 24}
} ;

const double STANDARD = 1.0 ;
const double MIDNIGHT = 1.5 ;
const double PEAKTIME = 1.3 ;

#endif
