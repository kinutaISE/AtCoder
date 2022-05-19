////////////////////////////////////////////////////////
// ./stream/input_stream.cpp
// 入力受付に関するクラスの実装ファイル（定義は input_stream.h ）

#include "input_stream.h"

using namespace std ;

// コンストラクタ
// 先頭行がヘッダファイルでない場合、第二引数として NO_HEADER を指定する
InputStream::InputStream(char *argv[], bool has_header = true) {
  /*
  argv[1]: 出力の形式
    - 不適切な出力の形式が入力されることはないことを前提とする
  argv[2]: 入力ファイル
    - 入力ファイルが存在することを前提とする
  has_header: 先頭行がヘッダ（属性名）であるかどうか
  */
  fstream file ;
  file.open(filename, ios::in) ;

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
int get_data_num() {
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
