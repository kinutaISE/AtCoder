#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std ;

////////////////////////////////////////////////////////////////
/*
./base_infomation.h
基本的な数値や科目名などを設定しておく
・科目数を表す定数
・科目名の一覧となるベクトル（中身はファイル読み込み時に格納）
・科目に対応する列挙体
・落第となる点数（科目ごとに異なることを考え配列とする）
*/
// #ifndef BASE_H_IFBIAKFO7891234_INCLUDED_ // 二重インクルード防止
// #define BASE_H_IFBIAKFO7891234_INCLUDED_

// #include <vector>

// 科目数
const int SUBJECT_NUM = 6 ;

// 科目名のベクトル
string subject_names[SUBJECT_NUM] ;

// 科目に対応する列挙体
enum SUBJECT {
  Mathematics,
  Science,
  English,
  Japanese,
  History,
  Geography,
} ;

// 科目ごとの落第点
const int BODER_LINES[SUBJECT_NUM] = {
  49,
  49,
  49,
  49,
  49,
  49
} ;

// #endif // BASE_H_IFBIAKFO7891234_INCLUDED_
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./student/student.h
学生のクラスを定義する（実装は ./student/student.cpp ）
*/

// #ifndef STUDENT_H_IAKOCAI89194_INCLUDED_ // 二重インクルード防止
// #define STUDENT_H_IAKOCAI89194_

// #include "../base_infomation.h"
// #include <vector>
// #include <string>

class Student {
protected:
  // メンバフィールド //////////
  string id ;
  int scores[SUBJECT_NUM] ; // 数学の点数 → scores[Mathematics]（SUBJECT型は base_infomation.h に定義）
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
  // 平均点を小数点以下2桁までで四捨五入した値にして返す関数
  float get_average_float() ;
  // 平均点を小数点以下2桁までの文字列として返す関数
  char* get_average() ;
  ///////////////////////////////////
  bool operator < (const Student &s) const ;
} ;

// #endif // STUDENT_H_IAKOCAI89194_INCLUDED_

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./student/student.cpp
学生クラスの実装（定義は ./student/student.h ）
*/

// #include "../base_infomation.h"
// #include "student.h"
// #include <vector>
// #include <string>
// #include <cstdlib>

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
  for (int st = 0 ; st < SUBJECT_NUM ; st++)
    dropout_count += is_dropout( (SUBJECT) st ) ;
  return dropout_count ;
}
// 落第かどうかを返す関数
bool Student::is_dropout(SUBJECT ST) {
  return ( scores[ST] <= BODER_LINES[ST] ) ;
}
// 平均点を返す関数
float Student::calculate_average() {
  float total = 0.0f ;
  for (int i = 0 ; i < SUBJECT_NUM ; i++)
    total += (float) scores[i] ;
  return total / SUBJECT_NUM ;
}
// 平均点を2桁までで四捨五入した値を返す関数
float Student::get_average_float() {
  return round(calculate_average() * 100) / 100 ;
}

// 平均点を2桁までの文字列として返す関数
char* Student::get_average() {
  char* average_str ;
  sprintf(average_str, "%.2f", get_average_float()) ;
  return average_str ;
}

bool Student::operator < (const Student &s) const {
  // return (this->get_id() < s.get_id()) ;
  return (id < s.id) ;
}


////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./functions/functions_str.cpp
文字列操作に関する関数の実装
*/

// #ifndef STR_CPP_AIKVCIAOBH78194_INCLUDED_ // 二重インクルード防止
// #define STR_CPP_AIKVCIAOBH78194_INCLUDED_

// #include <vector>
// #include <string>

// using namespace std ;

// 文字列 str を区切り文字 del として分割し、ベクトルとして返す関数
vector<string> split(string str, char del) {
  vector<string> result(1) ;
  int pos = 0 ;

  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result[pos] += c ;
  }

  return result ;
}

// #endif // STR_CPP_AIKVCIAOBH78194_INCLUDED_

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./functions/functions_input.cpp
入力の受け取りに関する関数の実装をする
*/
// #ifndef INPUT_CPP_DKIABIAK781847_INCLUDED_ // 二重インクルード防止
// #define INPUT_CPP_DKIABIAK781847_INCLUDED_

// #include "../base_infomation.cpp"
// #include "functions_str.cpp"
// #include "../student/student.h"
// #include <iostream>
// #include <fstream>
// #include <vector>
//
// using namespace std ;

// filename をもつファイルから入力を受け取り、学生のベクトル ss に格納する
int accept_input(char* filename, vector<Student>& ss) {
  fstream file;
  file.open(filename, ios::in) ;

  // ファイルが存在しなかった場合にエラーを返す
  if (! file.is_open()) {
    return EXIT_FAILURE ;
  }

  // ファイルの中身を一行ずつ読み込む
  string line ;
  bool is_first_row = true ;
  while ( getline(file, line) ) {
    if (is_first_row) {
      // 最初の行を読み取る
      // 科目名を受け取り、それを subject_names に格納
      auto items = split(line, ',') ;
      for (int i = 1 ; i <= SUBJECT_NUM ; i++)
        subject_names[i - 1] = items[i] ;
      is_first_row = false ;
      continue ;
    }
    // 2行目以降の情報（学生の情報）を読み取る
    auto data = split(line, ',') ;
    Student student(data) ;
    ss.push_back(student) ;
  }

  // ファイルを閉じる
  file.flush() ;
  file.close() ;

  return 0 ;
}

// #endif // INPUT_CPP_DKIABIAK781847_INCLUDED_
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./functions/functions_students.cpp
学生の情報を処理する関数
*/

// #ifndef FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_ // 二重インクルード防止
// #define FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_

// #include "../base_infomation.h"
// #include "../student/student.h"
// #include <vector>
// #include <string>
// #include <algorithm>

// s_num科目以上で落第となった学生を ID の辞書式基準でもつベクトルとして返す関数
vector<Student> get_dropout_students(vector<Student>& ss, int s_num) {
  vector<Student> dropouts ;

  for (Student s : ss) {
    if (s.get_dropout_num() >= s_num)
      dropouts.push_back(s) ;
  }
  sort(dropouts.begin(), dropouts.end()) ;
  return dropouts ;
}

// 最高の平均点をもつ学生を ID の辞書式基準でもつベクトルを返す
vector<Student> get_best_average_students(vector<Student> ss) {
  vector<Student> students ;
  float best_score = 0.0f ;
  for (Student s : ss) {
    float average_s = s.calculate_average() ;
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
vector<Student> get_worst_average_students(vector<Student> ss) {
  vector<Student> students ;
  float worst_score = 100.0f ;
  for (Student s : ss) {
    float average_s = s.calculate_average() ;
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

// 学生のベクトル ss に含まれている学生の ID と 平均点をカンマ区切りで出力する関数
void show_id_average(vector<Student> ss) {
  for (Student s : ss)
    cout << s.get_id() << "," << s.get_average_float() << endl ;
}


// #endif // FUNCTION_STUDENT_AKIVAOBIAIJI7921954_INCLUDED_
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
/*
./functions/functions_output.cpp
出力ファイルを作成する関数
*/

// #ifndef FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_ // 二重インクルード防止
// #define FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_
//
// #include "../base_infomation.h"
// #include "../student/student.h"
// #include "functions_student.cpp"
// #include <iostream>
// #include <vector>

// 2科目以上落第した学生を csv 形式で出力する
void output_dropouts(vector<Student> ss) {
  // 2科目以上落第した学生のベクトルを計算
  auto dropouts = get_dropout_students(ss, 2) ;
  // 以下で出力
  cout << "ID" << endl ;
  for (Student s : dropouts)
    cout << s.get_id() << endl ;
}

// 平均点が最低の学生全員、平均点が最高の学生の順に csv 形式で出力する
void output_top_vs_bottom(vector<Student> ss) {
  // 以下で出力
  cout << "ID,Mean" << endl ;

  auto worst_students = get_worst_average_students(ss) ;
  show_id_average(worst_students) ;

  auto best_students = get_best_average_students(ss) ;
  show_id_average(best_students) ;
}

// #endif // FUNCTION_OUTPUT_KAIKVOAI7919_INCLUDED_

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

// #include "base_infomation.h"
// #include "student/student.h"
// #include "functions/functions_input.cpp"
// #include "functions/functions_output.cpp"
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <vector>

// using namespace std;

int main(int argc, char *argv[]) {
  char* filename = argv[2] ;
  vector<Student> students ;
  accept_input(filename, students) ;
  char* output_type = argv[1] ;
  if ( ! strcmp(output_type, "dropouts") )
    output_dropouts(students) ;
  else if ( ! strcmp(output_type, "top-vs-bottom") )
    output_top_vs_bottom(students) ;
  return 0 ;
}
