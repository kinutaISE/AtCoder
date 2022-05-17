#ifndef INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
#define INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_

#include <iostream>
#include <fstream>
#include <vector>

const char DELIMITER = ',' ;

class InputStream {
protected:
  string line_header ;
  vector<string> lines_data ;
public:
  InputStream(char* filename[]) ;
  InputStream(string filename) ;
  vector<string> get_attributes() ;
  vector< vector<string> > get_student_info() ;
  vector<string> split(string str, char del = DELIMITER) ;
} ;

#endif // INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
