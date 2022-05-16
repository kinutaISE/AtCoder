#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std ;

int main() {
  fstream file_r ;
  file_r.open("test.csv", ios::in) ;
  if (! file_r.is_open()) {
    return EXIT_FAILURE ;
  }
  fstream file_w ;
  file_w.open("output.csv", ios::out) ;
  string line ;
  // getline(file, line) ;
  // cout << line << endl ;
  // getline(file, line) ;
  // cout << line << endl ;
  int line_count = 0 ;
  while ( getline(file_r, line) ) {
    line_count++ ;
    cout << line << endl ;
    file_w << line_count << ". " << line << endl ;
  }
  file_r.flush() ;
  file_r.close() ;
  file_w.flush() ;
  file_w.close() ;
}
