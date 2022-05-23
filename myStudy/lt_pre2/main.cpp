#include "base_info.h"
#include "record/record.cpp"
#include "meter/meters.cpp"

int main(int argc, char *argv[]) {
  Meters meters ;
  string line ;
  bool is_init_record = true ;
  while ( !cin.eof() ) {
    getline(cin, line) ;

    if (line == "")
      break ;

    Record record(line) ;
    if (is_init_record) {
      meters.initialize(record) ;
      is_init_record = false ;
      continue ;
    }
    meters.update(record) ;
  }
  cout << meters.get_total_fare() << endl ;
  return 0 ;
}
