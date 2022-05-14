#ifndef READEF1_R_20220514_DIEBIA78219_INCLUDE_
#define READEF1_R_20220514_DIEBIA78219_INCLUDE_

#include "../structs/student.h"
#include "../functions/functions_string.h"
#include <iostream>
#include <vector>

using namespace std ;

// プロトタイプ ////////////////////////////////////////
void accept_input(vector<Student>* ss) ;

// 定義 //////////////////////////////////////////////
void accept_input(vector<Student>* ss) {
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    Student student = Student(line) ;
    ss->push_back(student) ;
  }
}

////////////////////////////////////////////////////////////////

#endif
