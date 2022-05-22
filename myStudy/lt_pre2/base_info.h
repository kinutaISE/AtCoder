#ifndef BASE_INFO_H_ECIAOEI89138_INCLUDED_
#define BASE_INFO_H_ECIAOEI89138_INCLUDED_

#include <string>
#include <map>

map< string, map<string, int> > time_separations ;

time_separations["MIDNIGHT"]["START"] = 0 ;
time_separations["MIDNIGHT"]["FINISH"] = 6 * 24 * 60 ;
time_separations["PEAKTIME_MORNING"]["START"] = 6 * 24 * 60 ;
time_separations["PEAKTIEM_MORNING"]["FINISH"] = 9 * 24 * 60 + 30 * 60 ;
time_separations["STANDARD"]["START"] = 9 * 24 * 60 + 30 * 60 ;
time_separations["STANDARD"]["FINISH"] = 18 * 24 * 60 ;
time_separations["PEAKTIME_NIGHT"]["START"] = 18 * 24 ;
time_separations["PEAKTIME_NIGHT"]["FINISH"] = 24 * 24 ;

enum MAGNIFICATION {
  STANDARD = 1.0,
  MIDNIGHT = 1.5,
  PEAKTIME = 1.3
}

#endif
