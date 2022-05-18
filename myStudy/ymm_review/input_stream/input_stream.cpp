#include "input_stream.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std ;

InputStream::InputStream(char* filename) {
  fstream file ;
  file.open(filename, ios::in) ;

  // 先頭行の読み込み
  getline(file, line_header) ;

  // 以降の行の読み込み
  string line ;
  while ( getline(file, line) )
    lines_data.push_back(line) ;
}
InputStream::InputStream(string filename) {
  InputStream(filename.c_str());
}
void InputStream::show_input() {
  cout << line_header << endl ;
  for (string line : lines_data)
    cout << line << endl ;
}
vector<string> InputStream::get_attributes() {
  return split(line_header) ;
}
vector<string> InputStream::get_student_info(int i) {
  return split(lines_data[i]) ;
}
vector<string> InputStream::split(const string str, char del) {
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
