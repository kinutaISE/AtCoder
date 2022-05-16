////////////////////////////////////////////////////////////////
/*
./functions/functions_students.cpp
学生の情報を処理する関数
*/

#ifndef FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_ // 二重インクルード防止
#define FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_

#include "../base_infomation.h"
#include "../student/student.h"
#include <vector>
#include <string>
#include <algorithm>

// s_num科目以上で落第となった学生を ID の辞書式基準でもつベクトルとして返す関数
vector<Student> get_dropout_students(const vector<Student>& ss, int s_num) {
  vector<Student> dropouts ;

  for (const Student s : ss) {
    if (s.get_dropout_num() >= s_num)
      dropouts.push_back(s) ;
  }
  sort(dropouts.begin(), dropouts.end()) ;
  return dropouts ;
}

// 最高の平均点をもつ学生を ID の辞書式基準でもつベクトルを返す
vector<Student> get_best_average_students(const vector<Student> ss) {
  vector<Student> students ;
  float best_score = 0.0f ;
  for (const Student s : ss) {
    float average_s = s.get_average() ;
    if (best_score < average_s) {
      students.clear() ;
      students.push_back(s) ;
      best_score = average_s ;
      continue ;
    }
    if (best_score > average_s)
      continue ;
    students.push_back(s) ;
  }
  sort(students.begin(), students.end()) ;
  return students ;
}

// 最低の平均点をもつ学生を ID の辞書式基準でもつベクトルを返す
vector<Student> get_worst_average_students(const vector<Student> ss) {
  vector<Student> students ;
  float worst_score = 0.0f ;
  for (const Student s : ss) {
    float average_s = s.get_average() ;
    if (worst_score > average_s) {
      students.clear() ;
      students.push_back(s) ;
      worst_score = average_s ;
      continue ;
    }
    if (worst_score < average_s)
      continue ;
    students.push_back(s) ;
  }
  sort(students.begin(), students.end()) ;
  return students ;
}

void show_id_average(vector<Student> ss) {
  for (Student s : ss)
    cout << s.get_id() << "," << s.get_average() << endl ;
}


#endif // FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_
////////////////////////////////////////////////////////////////
