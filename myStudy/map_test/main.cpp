#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
  map<string, double> time_separations ;
  time_separations["MIDNIGHT_START"] = 0.0 ;
  time_separations["MIDNIGHT_FINISH"] = 6.0 * 24 * 60 ;
  time_separations["PEAKTIME_MORNING_START"] = 6.0 * 24 * 60 ;
  time_separations["PEAKTIEM_MORNING_FINISH"] = 9.0 * 24 * 60 + 30 * 60 ;
  time_separations["STANDARD_START"] = 9.0 * 24 * 60 + 30 * 60 ;
  time_separations["STANDARD_FINISH"] = 18.0 * 24 * 60 ;
  time_separations["PEAKTIME_NIGHT_START"] = 18.0 * 24 ;
  time_separations["PEAKTIME_NIGHT_FINISH"] = 24.0 * 24 ;

  cout << time_separations.at("MIDNIGHT_START") << endl;
}
