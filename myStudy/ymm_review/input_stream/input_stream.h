#ifndef INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
#define INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std ;

const char DELIMITER = ',' ;

class InputStream {
protected:
  string line_header ;
  vector<string> lines_data ;
public:
  InputStream(char* filename) ;
  InputStream(string filename) ;
  void show_input() ;
  vector<string> get_attributes() ;
  vector<string> get_student_info(int i) ;
  vector<string> split(string str, char del = DELIMITER) ;
} ;

#endif // INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
