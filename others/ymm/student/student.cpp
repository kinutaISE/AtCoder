////////////////////////////////////////////////////////////////
/*
./student/student.cpp
学生クラスの実装（定義は ./student/student.h ）
*/

#include "../base_infomation.h"
#include "student.h"
#include <vector>
#include <string>
#include <cstdlib>

// 平均点を返す関数
float Student::calculate_average() {
  float total = 0.0f ;
  for (int score : scores)
    total += score ;
  return total / SUBJECT_NUM ;
}

// コンストラクタ
Student::Student(vector<string> data) {
  id = data[0] ;
  for (int i = 1 ; i <= SUBJECT_NUM ; i++)
    scores[i - 1] = stoi(data[i]) ;
}

// ID を返す関数
string Student::get_id() {
  return id ;
}
// 科目の点数を返す関数
int Student::get_score(SUBJECT ST) {
  return scores[ST] ;
}
// 落第した科目数を返す関数
int Student::get_dropout_num() {
  int dropout_count = 0 ;
  for (int st = 0 ; st < SUBJECT_NUM ; i++)
    dropout_count += is_dropout( (SUBJECT) st ) ;
  return dropout_count ;
}
// 落第かどうかを返す関数
bool Student::is_dropout(SUBJECT ST) {
  return ( scores[ST] <= BODER_LINES[ST] ) ;
}
// 平均点を2桁までの文字列として返す関数
string Student::get_average() {
  string average_str ;
  sprintf(average_str, "%.2f", calculate_average()) ;
  return average_str ;
}


////////////////////////////////////////////////////////////////
