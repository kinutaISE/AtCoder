////////////////////////////////////////////////////////
// ./student/student.cpp
// 学生クラスの実装（定義は student.h ）

#include "student.h"

using namespace std ;

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
  auto student_info = in.get_student_info(i) ;
  for (int j = 1 ; j < attributes.size() ; j++) {
    string subject_name = attributes[j] ;
    if (! student_info[j] ) {
      // 科目 subject_name を受験していない場合
      is_examined[attribute] = false ;
      continue ;
    }
    // 科目 st_name を受験している場合
    is_examined[attribute] = true ;
    scores[attribute] = stoi(student_info[j]) ;
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
bool Student::is_examined(string st_name) const {
  return is_examined[st_name] ;
}
// 科目 st_name の点数を返す関数
unsigned int Student::get_score(string st_name) const {
  return scores[st_name] ;
}
// 落第した科目数を返す関数
unsigned int get_dropout_num() const {
  unsigned int count = 0 ;
  for (auto p : scores)
    cout += (p.second <= BODER_LINE) ;
  return count ;
}
// 平均点を小数点以下の桁数 d 桁で四捨五入して返す関数
float Student::get_average(unsigned int d) const {
  int ten_pow = pow(10, d) ;
  return round( average * ten_pow ) / ten_pow ;
}
// 比較演算子のオーバーライド（学生IDの辞書式順序に従って比較する）
Student::operator < (const Student &s) const {
  return (id < s.get_id()) ;
}
/////////////////////////////////////////////////
// StudentSetクラス
// コンストラクタ
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
vector<Student> StudentSet::get_dropout_students(int st_num) const {
  vector<Student> dropouts ;
  for (Student &s : container) {
    if (s.get_dropout_num() >= st_num)
      dropouts.push_back(s) ;
  }
  return dropouts ;
}
// 平均点が最高の学生のベクトルを返す関数
vector<Student> StudentSet::get_top_students(bool is_asc) const {
  vector<Student> tops ;
  float best_score = 0.0f ;

  for (Student &s : container) {
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
  float worst_score = 100.0f ;

  for (Student &s : container) {
    float average_s = s.get_average() ;
    if (worst_score < average_s)
      continue ;
    if (worstt_score > average_s) {
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
