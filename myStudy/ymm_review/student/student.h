/*
学生クラスの定義（実装は student.cpp ）
*/

#ifndef STUDENT_H_IAKOCAKAIV81929_INCLUDED_
#define STUDENT_H_IAKOCAKAIV81929_INCLUDED_

#include "../base_infomation.h"
#include "../input_stream/input_stream.h"
#include <map>

class Student {
protected:
  string id ;
  map<string, unsigned int> scores ;
public:
  Student(InputSetream &in, int i) ;
  string get_id() ; // id を返す
  int get_score(string subject_name) ; // 科目名を指定し、その科目の点数を返す
  float get_average(int d = 2) ; // 平均点を返す
} ;

class StudentSet {
protected:
  vector<Student> students ;
public:
  StudentSet(InputSetream &in) ;
  void add(Student &s) ;
  StudentSet get_dropouts_students(int st_num = 2) ;
  StudentSet get_best_students() ;
  StudentSet get_worst_students() ;
} ;

#endif // STUDENT_H_IAKOCAKAIV81929_INCLUDED_
