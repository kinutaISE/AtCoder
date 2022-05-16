/*
生徒のクラス定義
・Student：学生クラス（継承されることを前提としたクラス）
  ・親クラス：なし
・ElementarySchoolStudent：小学生クラス
  ・親クラス：Student
*/

#ifndef STUDENT_H_DIJIAHBI8918_INCLUDED_ // 二重インクルードの防止
#define STUDENT_H_DIJIAHBI8918_INCLUDED_ // マクロの定義

#include <iostream>
#include <vector>

using namespace std ;

// 学生クラス /////////////////////////////////////////////////////////////
// 各種定数・列挙子 //////////////////////////////////////////////////
// 性別
enum GENDER {
  BOY,
  GIRL,
} ;
const char* gender_str[] = {
  "boy",
  "girl"
} ;


///////////////////////////////////////////////////////////////////
// クラス定義 //////////////////////////////////////////////////////
class Student {
protected:
  string id ;               // 学生番号
  string name ;             // 名前
  GENDER gender ;           // 性別
  float height ;            // 身長
  float weight ;            // 体重
  vector<Student> friends ; // 友人
public:
  // コンストラクタ //////////////////
  Student(string line) ;
  Student(vector<string> data) ;
  //////////////////////////////////
  // 外部からメンバを得るための関数 /////
  string get_id() ;
  string get_name() ;
  string get_gender() ;
  float get_height() ;
  float get_weight() ;
  vector<Student> get_friends() ;
  /////////////////////////////////

  // メンバの値のみから計算できる値を得る関数 /////
  // 学生の情報を出力する関数（継承先によって差異あり）
  char* get_info() ;
  // BMI を小数点以下1桁までで出力する関数
  float get_BMI() ;
  // 友人の一覧を文字列として返す関数
  string get_friends_str() ;
  //////////////////////////////////////////
} ;
////////////////////////////////////////////////////////////////

// 小学生クラス /////////////////////////////////////////////////////////////
// クラス定義 //////////////////////////////////////////////////////
class ElementarySchoolStudent : public Student {
using Student::Student ;
protected:
  int grade ;
  int class_number ;
public:
  // コンストラクタ //////////////////
  ElementarySchoolStudent(string line) ;
  ElementarySchoolStudent(vector<string> data) ;
  /////////////////////////////////
  // 外部からメンバを得るための関数 /////
  int get_grade() ;
  int get_class_number() ;
  /////////////////////////////////
  // メンバの値のみから計算できる値を得る関数 /////
  // 学生の情報を出力する関数（継承先によって差異あり）
  char* get_info() ;
  //////////////////////////////////////////
} ;
////////////////////////////////////////////////////////////////

#endif
