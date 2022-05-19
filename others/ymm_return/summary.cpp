#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std ;

////////////////////////////////////////////////////////
// base_info.h
// 基本的な情報（落第の点数など）を設定するヘッダファイル

// #ifndef BASE_INFO_H_WSIAQKH29400_INCLUDED_ // 二重インクルード防止
// #define BASE_INFO_H_WSIAQKH29400_INCLUDED_

// 点数の下限
const float SCORE_LOWER = 0.0f ;

// 点数の上限
const float SCORE_UPPER = 100.0f ;

// 落第となる点数
const int BODER_LINE = 49 ;

// #endif // BASE_INFO_H_WSIAQKH29400_INCLUDED_
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./stream/input_stream.h
// 入力受付に関するクラスの定義ファイル（実装は input_stream.cpp ）
// #ifndef INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_ // 二重インクルード防止
// #define INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_

// #include "../base_info.h"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>

// 先頭行がヘッダでない場合にコンストラクタの第二引数に与える値
const bool NO_HEADER = false ;

// デフォルトの入力ファイルの属性名
const string DEFAULT_LINE_HEADER = "ID,Mathematics,Science,English,Japanese,History,Geography" ;

// デフォルトの区切り文字を表す定数
const char DEFAULT_DELIMITER = ',' ;

// InputStream クラスの定義
class InputStream {
protected:
  // メンバフィールド
  string output_type ;        // 出力の形式
  int data_num ;              // データ数
  string line_header ;        // 入力ファイルの先頭行
  vector<string> lines_data ; // 入力ファイルの2行目以降
public:
  // コンストラクタ
  InputStream() ;
  InputStream(char *argv[], bool has_header = true) ;

  // メンバ関数
  // データ数を返す関数
  int get_data_num() const ;
  // データの属性を文字列のベクトルとして返す関数
  vector<string> get_attributes() const ;
  // i 番目の学生のデータを文字列のベクトルとして返す関数
  vector<string> get_student_data(int i) const ;
  // 区切り文字 del として str を分割し、その結果を文字列のベクトルとして返す関数
  vector<string> split(string str, char del = DEFAULT_DELIMITER) const ;
  // 出力形式を返す関数
  string get_output_type() const ;
} ;

// #endif // INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./stream/input_stream.cpp
// 入力受付に関するクラスの実装ファイル（定義は input_stream.h ）

// #include "input_stream.h"

using namespace std ;

// コンストラクタ
InputStream::InputStream() {
  data_num = 0 ;
}
// 先頭行がヘッダファイルでない場合、第二引数として NO_HEADER を指定する
InputStream::InputStream(char *argv[], bool has_header) {
  /*
  argv[1]: 出力の形式
    - 不適切な出力の形式が入力されることはないことを前提とする
  argv[2]: 入力ファイル
    - 入力ファイルが存在することを前提とする
  has_header: 先頭行がヘッダ（属性名）であるかどうか
  */
  output_type = argv[1] ;
  fstream file ;
  file.open(argv[2], ios::in) ;

  if (has_header) {
    // 先頭行がヘッダの場合
    getline(file, line_header) ;
  } else {
    // 先頭行がヘッダでない場合
    line_header = DEFAULT_LINE_HEADER ;
  }
  data_num = 0 ;
  string line ;
  while ( getline(file, line) ) {
    data_num++ ;
    lines_data.push_back(line) ;
  }

  file.flush() ;
  file.close() ;
}

// メンバ関数
// データ数を返す関数
int InputStream::get_data_num() const {
  return data_num ;
}
// データの属性を文字列のベクトルとして返す関数
vector<string> InputStream::get_attributes() const {
  return split(line_header) ;
}
// i 番目の学生のデータを文字列のベクトルとして返す関数
vector<string> InputStream::get_student_data(int i) const {
  /*
  入力ファイルの上から i 行目（i = 0, 1, ...）を文字列のベクトルとして返す関数
  */
  return split(lines_data[i]) ;
}
// 区切り文字 del として str を分割し、その結果を文字列のベクトルとして返す関数
vector<string> InputStream::split(string str, char del) const {
  /*
  str: 分割の対象となる文字列
  del: 区切り文字（デフォルト値は ,（カンマ））
  */
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
// 出力の形式を返す関数
string InputStream::get_output_type() const {
  return output_type ;
}

////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./student/student.h
// 学生クラスの定義ファイル （実装は student.cpp ）

// #ifndef STUDENT_H_IAKOCAI89194_INCLUDED_ // 二重インクルード防止
// #define STUDENT_H_IAKOCAI89194_INCLUDED_

// #include "../base_info.h"
// #include "../stream/input_stram.h"
// #include <vector>
// #include <string>
// #include <map>
// #include <cmath>

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
  Student(const InputStream &in, int i) ;

  // メンバ関数
  // 学生IDを返す関数
  string get_id() const ;
  // 科目 st_name を受験したかどうかを返す関数
  bool is_examined_st(string st_name) const ;
  // 科目 st_name の点数を返す関数
  unsigned int get_score(string st_name) const ;
  // 落第した科目数を返す関数
  unsigned int get_dropout_num() const ;
  // 平均点を小数点以下の桁数 d 桁で四捨五入して返す関数
  float get_average(unsigned int d = 2) const ;
  // 比較演算子のオーバーライド（学生IDの辞書式順序に従って比較する）
  bool operator < (const Student &s) const ;
} ;

// 複数の学生をベクトルに格納する際に降順としたい場合に、これを引数に与える（デフォルトは昇順）
const bool DESC = false ;

class StudentSet {
protected:
  // メンバフィールド
  int student_num ;           // 学生数
  vector<Student> container ; // 学生を保持するベクトル
public:
  // コンストラクタ
  StudentSet() ;
  StudentSet(const InputStream &in) ;

  // メンバ関数
  // 学生数を返す関数
  int get_student_num() const ;
  // st_num 科目で落第した学生のベクトルを返す関数
  vector<Student> get_dropout_students(int st_num = 2, bool is_asc = true) const ;
  // 平均点が最高の学生のベクトルを返す関数
  vector<Student> get_top_students(bool is_asc = true) const ;
  // 平均点が最低の学生のベクトルを返す関数
  vector<Student> get_bottom_students(bool is_asc = true) const ;
} ;

// #endif // STUDENT_H_IAKOCAI89194_INCLUDED_
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./student/student.cpp
// 学生クラスの実装（定義は student.h ）

// #include "student.h"
//
// using namespace std ;

/////////////////////////////////////////////////
// Student クラス
// コンストラクタ
Student::Student(const InputStream &in, int i) {
  /*
  attributes: 学生の持つ情報のヘッダ（属性）をもつベクトル
   - 先頭は学生IDを表すIDであることを前提とする
  student_info: 各属性の値をもつベクトル
   - 欠損値がないと仮定する
   - 今後の拡張として、学生ごとに受験科目が異なる場合が考えられるため、is_examined に科目を受験したかどうかを格納する
  */
  auto attributes = in.get_attributes() ;
  auto student_info = in.get_student_data(i) ;
  id = student_info[0] ;
  for (int j = 1 ; j < attributes.size() ; j++) {
    string subject_name = attributes[j] ;
    if (student_info[j] == "") {
      // 科目 subject_name を受験していない場合
      is_examined[subject_name] = false ;
      continue ;
    }
    // 科目 st_name を受験している場合
    is_examined[subject_name] = true ;
    scores[subject_name] = stoi(student_info[j]) ;
  }
  // 平均値を設定する
  set_average() ;
}

// 平均点を計算し average に代入する（コンストラクタで呼び出す）
void Student::set_average() {
  average = 0.0f ;
  for (auto p : scores)
    average += p.second ;
  average /= scores.size() ;
}
// 学生IDを返す関数
string Student::get_id() const {
  return id ;
}
// 科目 st_name を受験したかどうかを返す関数
bool Student::is_examined_st(string st_name) const {
  return is_examined.at(st_name) ;
}
// 科目 st_name の点数を返す関数
unsigned int Student::get_score(string st_name) const {
  return scores.at(st_name) ;
}
// 落第した科目数を返す関数
unsigned int Student::get_dropout_num() const {
  unsigned int count = 0 ;
  for (auto p : scores)
    count += (p.second <= BODER_LINE) ;
  return count ;
}
// 平均点を小数点以下の桁数 d 桁で四捨五入して返す関数
float Student::get_average(unsigned int d) const {
  int ten_pow = pow(10, d) ;
  return round( average * ten_pow ) / ten_pow ;
}
// 比較演算子のオーバーライド（学生IDの辞書式順序に従って比較する）
bool Student::operator < (const Student &s) const {
  return ( get_id() < s.get_id() ) ;
}
/////////////////////////////////////////////////
// StudentSetクラス
// コンストラクタ
StudentSet::StudentSet() {
  student_num = 0 ;
}
StudentSet::StudentSet(const InputStream &in) {
  for (int i = 0 ; i < in.get_data_num() ; i++) {
    student_num++ ;
    Student student(in, i) ;
    container.push_back(student) ;
  }
}

// メンバ関数
// 学生数を返す関数
int StudentSet::get_student_num() const {
  return student_num ;
}
// st_num 科目で落第した学生のベクトルを返す関数
vector<Student> StudentSet::get_dropout_students(int st_num, bool is_asc) const {
  vector<Student> dropouts ;
  for (const Student &s : container) {
    if (s.get_dropout_num() >= st_num)
      dropouts.push_back(s) ;
  }
  sort(dropouts.begin(), dropouts.end()) ;
  if (! is_asc)
    reverse(dropouts.begin(), dropouts.end()) ;
  return dropouts ;
}
// 平均点が最高の学生のベクトルを返す関数
vector<Student> StudentSet::get_top_students(bool is_asc) const {
  vector<Student> tops ;
  float best_score = SCORE_LOWER ;

  for (const Student &s : container) {
    float average_s = s.get_average() ;
    if (best_score > average_s)
      continue ;
    if (best_score < average_s) {
      tops.clear() ;
      best_score = average_s ;
    }
    tops.push_back(s) ;
  }

  sort(tops.begin(), tops.end()) ;
  if (! is_asc)
    reverse(tops.begin(), tops.end()) ;

  return tops ;
}
// 平均点が最低の学生のベクトルを返す関数
vector<Student> StudentSet::get_bottom_students(bool is_asc) const {
  vector<Student> bottoms ;
  float worst_score = SCORE_UPPER ;

  for (const Student &s : container) {
    float average_s = s.get_average() ;
    if (worst_score < average_s)
      continue ;
    if (worst_score > average_s) {
      bottoms.clear() ;
      worst_score = average_s ;
    }
    bottoms.push_back(s) ;
  }

  sort(bottoms.begin(), bottoms.end()) ;
  if (! is_asc)
    reverse(bottoms.begin(), bottoms.end()) ;

  return bottoms ;
}
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./stream/output_stream.h
// 出力に関するクラスの定義ファイル（実装は output_stream.cpp ）

// #ifndef OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_ // 二重インクルード防止
// #define OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_
//
// #include "../base_info.h"
// #include "input_stream.h"
// #include <iostream>
// #include <vector>

class OutputStream {
protected:
  // メンバフィールド
  InputStream istream ;
  StudentSet students ;
public:
  // コンストラクタ
  OutputStream(const InputStream &in, const StudentSet &ss) ;

  // メンバ関数
  // 出力をする関数（output_dropouts() または output_top_vs_bottom() を呼び出す）
  void output() const ;
  // 出力形式が dropouts の場合の出力をする関数
  void output_dropouts() const ;
  // 出力形式が top-vs-bottom の場合の出力をする関数
  void output_top_vs_bottom() const ;
} ;

// #endif // OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// ./stream/output_stream.cpp
// 出力に関するクラスの実装（定義は output_stream.h ）

// #include "output_stream.h"
//
// using namespace std ;

// コンストラクタ
OutputStream::OutputStream(const InputStream &in, const StudentSet &ss) {
  istream = in ;
  students = ss ;
}

// メンバ関数
// 出力をする関数（output_dropouts() または output_top_vs_bottom() を呼び出す）
void OutputStream::output() const {
  string output_type = istream.get_output_type() ;
  if (output_type == "dropouts")
    output_dropouts() ;
  else if (output_type == "top-vs-bottom")
    output_top_vs_bottom() ;
}
// 出力形式が dropouts の場合の出力をする関数
void OutputStream::output_dropouts() const {
  auto dropouts = students.get_dropout_students() ;

  cout << "ID" << endl ;
  for (Student &s : dropouts)
    cout << s.get_id() << endl ;
}
// 出力形式が top-vs-bottom の場合の出力をする関数
void OutputStream::output_top_vs_bottom() const {
  auto tops = students.get_top_students() ;
  auto bottoms = students.get_bottom_students() ;

  cout << "ID,Mean" << endl ;
  // for (Student &s : bottoms) {
  //   char* average_s_str ;
  //   sprintf( average_s_str, "%.2f", s.get_average() );
  //   cout << s.get_id() << ',' << average_s_str << endl ;
  // }
  // for (Student &s : tops) {
  //   char* average_s_str ;
  //   sprintf( average_s_str, "%.2f", s.get_average() );
  //   cout << s.get_id() << ',' << average_s_str << endl ;
  // }
  for (Student &s : bottoms)
    cout << s.get_id() << ',' << s.get_average() << endl ;

  for (Student &s : tops)
    cout << s.get_id() << ',' << s.get_average() << endl ;
}
////////////////////////////////////////////////////////
// ./main.cpp

// #include "base_info.h"
// #include "stream/input_stream.h"
// #include "student/student.h"
// #include "stream/output_stream.h"
// #include <iostream>

int main(int argc, char *argv[]) {
  // 浮動小数点数の出力精度の設定
  cout << fixed << setprecision(2) ;

  InputStream istream(argv) ;
  StudentSet students(istream) ;
  OutputStream ostream(istream, students) ;
  ostream.output() ;
  return 0 ;
}
