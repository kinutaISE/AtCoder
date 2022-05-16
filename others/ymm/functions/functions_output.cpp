////////////////////////////////////////////////////////////////
/*
./functions/functions_output.cpp
出力ファイルを作成する関数
*/

#ifndef FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_ // 二重インクルード防止
#define FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_

#include "../base_infomation.h"
#include "../student/student.h"
#include "functions_student.cpp"
#include <iostream>
#include <vector>

// 2科目以上落第した学生を csv 形式で出力する
void output_dropouts(const vector<Student> ss) {
  // 2科目以上落第した学生のベクトルを計算
  auto dropouts = get_dropout_students(ss, 2) ;
  // 以下で出力
  cout << "ID" << endl ;
  for (Student s : dropouts)
    cout << s.get_id() << endl ;
}

// 平均点が最低の学生全員、平均点が最高の学生の順に csv 形式で出力する
void output_top_vs_bottom(const vector<Student> ss) {
  // 平均点が最高の学生のベクトルを計算
  auto best_students = get_best_average_students(ss) ;
  auto worst_students = get_worst_average_students(ss) ;
  // 以下で出力
  cout << "ID,Mean" << endl ;
  show_id_average(worst_students) ;
  show_id_average(best_students) ;
}

#endif // FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_

////////////////////////////////////////////////////////////////
