////////////////////////////////////////////////////////////////
/*
./student/student.h
学生のクラスを定義する（実装は ./student/student.cpp ）
*/

#ifndef STUDENT_H_IAKOCAI89194_INCLUDED_ // 二重インクルード防止
#define STUDENT_H_IAKOCAI89194_

#include "../base_infomation.h"
#include <vector>
#include <string>

class Student {
protected:
  // メンバフィールド //////////
  string id ;
  SUBJECT scores[SUBJECT_NUM] ; // 数学の点数 → scores[Mathematics]（SUBJECT型は base_infomation.h に定義）
  ///////////////////////////
public:
  // コンストラクタ //////////////////
  Student(vector<string> data) ;
  /////////////////////////////////
  // メンバフィールドから得られる値の計算 //
  // ID を返す関数
  string get_id() ;
  // 科目STの点数を返す関数
  int get_score(SUBJECT ST) ;
  // 落第した科目数を返す関数
  int get_dropout_num() ;
  // 科目STが落第かどうかを返す関数
  bool is_dropout(SUBJECT ST) ;
  // 平均点を返す関数
  float calculate_average() ;
  // 平均点を2桁までの文字列として返す関数
  string get_average() ;
  ///////////////////////////////////
  Student operator< (const Student s) const {
    return (id < s.get_id()) ;
  }
} ;

#endif // STUDENT_H_IAKOCAI89194_INCLUDED_

////////////////////////////////////////////////////////////////
