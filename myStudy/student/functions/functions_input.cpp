// 入力に関する関数の実装（定義は functions_input.h）

#include "functions_input.h"
#include <iostream>
#include <vector>

void accept_input(vector<Student>& ss) {
  cout << "ID NAME GENDER HEIGHT WEIGHT" << endl ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    Student student(line) ;
    ss.push_back( student );
  }
}
