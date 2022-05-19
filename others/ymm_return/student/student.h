////////////////////////////////////////////////////////
// ./student/student.h
// 学生クラスの定義ファイル （実装は student.cpp ）

#ifndef STUDENT_H_IAKOCAI89194_INCLUDED_ // 二重インクルード防止
#define STUDENT_H_IAKOCAI89194_INCLUDED_

#include "../base_info.h"
#include "../stream/input_stram.h"
#include <vector>
#include <string>
#include <map>
#include <cmath>

class Student {
protected:
  // メンバフィールド
  string id ;                         // 学生ID
  map<string, bool> is_examined ;     // 各科目を受験したかどうか
  map<string, unsigned int> scores ;  // 各科目の点数
  float average ;                     // 受験した科目の平均点

  // メンバ関数
  // 平均点を計算し average に代入する（コンストラクタで呼び出す）
  void set_average() ;
public:
  // コンストラクタ
  Student(const InputStream &in) ;

  // メンバ関数
  // 学生IDを返す関数
  string get_id() const ;
  // 科目 st_name を受験したかどうかを返す関数
  bool is_examined(string st_name) const ;
  // 科目 st_name の点数を返す関数
  unsigned int get_score(string st_name) const ;
  // 落第した科目数を返す関数
  unsigned int get_dropout_num() const ;
  // 平均点を小数点以下の桁数 d 桁で四捨五入して返す関数
  float get_average(unsigned int d = 2) const ;
  // 比較演算子のオーバーライド（学生IDの辞書式順序に従って比較する）
  operator < (const Student &s) const ;
} ;

const bool DESC = false ;

class StudentSet {
protected:
  // メンバフィールド
  int student_num ;           // 学生数
  vector<Student> container ; // 学生を保持するベクトル
public:
  // コンストラクタ
  StudentSet(const InputStream &in) ;

  // メンバ関数
  // 学生数を返す関数
  int get_student_num() const ;
  // st_num 科目で落第した学生のベクトルを返す関数
  vector<Student> get_dropout_students(int st_num = 2) const ;
  // 平均点が最高の学生のベクトルを返す関数
  vector<Student> get_top_students(bool is_asc = true) const ;
  // 平均点が最低の学生のベクトルを返す関数
  vector<Student> get_bottom_students(bool is_asc = true) const ;
} ;

#endif // STUDENT_H_IAKOCAI89194_INCLUDED_
////////////////////////////////////////////////////////
