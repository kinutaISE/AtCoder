#include "input_stream.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std ;

InputStream::InputStream(char* filename[]) {
  fstream file ;
  file.open(filename, ios::in) ;

  // 先頭行の読み込み
  getline(file, line_header) ;

  // 以降の行の読み込み
  string line ;
  while ( getline(file, line) )
    line_data.push_back(line) ;
}
InputStream::InputStream(string filename) {
  InputStream(filename.c_str());
}
vector<string> get_attributes() {
  return split(line_header) ;
}
vector< vector<string> > get_student_info() {
  vector< vector<string> > student_info_container ;
  for (auto line : lines_data) {
    student_info_container.push_back( split(line) ) ;
  }
  return student_info_container ;
}
vector<string> split(const string str, char del = DELIMITER) {
  vector<string> result(1) ;
  int pos = 0 ;
  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result[pos] += c ;
  }
  return result ;
}
