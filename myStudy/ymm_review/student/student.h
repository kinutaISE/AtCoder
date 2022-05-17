/*
学生クラスの定義（実装は student.cpp ）
*/

#ifndef STUDENT_H_IAKOCAKAIV81929_INCLUDED_
#define STUDENT_H_IAKOCAKAIV81929_INCLUDED_

#include "../base_infomation.h"
#include <map>

class Student {
protected:
  string id ;
  map<string, unsigned int> scores ;
public:
  Student() ;
  string get_id() ;
  int get_score(string subject_name) ;
  float get_average() ;
} ;

#endif // STUDENT_H_IAKOCAKAIV81929_INCLUDED_
