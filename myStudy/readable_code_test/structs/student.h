#ifndef READEF1_R_20220514_HDIZBIA7928_INCLUDE_
#define READEF1_R_20220514_HDIZBIA7928_INCLUDE_

#include "../functions/functions_string.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std ;

// 生徒の状態を意味する変数
enum STATUS {
  VERY_GOOD,
  GOOD,
  OK,
  BAD
} ;

struct Student {
  string id ;
  string name ;
  int score ;
  STATUS status ;
  Student(const string data) {
    cout << "data: " << data << endl ;

    auto student_info_str = split(data, ' ') ;

    cout << student_info_str[0] << " "
      << student_info_str[1] << " "
      << student_info_str[2] << " "
      << student_info_str[3] << endl ;

    id = student_info_str[0] ;
    name = student_info_str[1] ;
    score = stoi(student_info_str[2]) ;
    status = (student_info_str[3] == "VERY_GOOD") ? VERY_GOOD :
      (student_info_str[3] == "GOOD") ? GOOD :
      (student_info_str[3] == "OK") ? OK : BAD ;
  }
  void show_info() const{
    static const char* status_str[] = {
      "VERY GOOD!!",
      "GOOD!",
      "OK",
      "BAD..."
    } ;
    cout << "id: " << id << endl
         << "score: " << score << endl
         << "status: " << status_str[status] << endl ;
  }
} ;

#endif
