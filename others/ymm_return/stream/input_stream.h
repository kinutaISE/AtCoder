////////////////////////////////////////////////////////
// ./stream/input_stream.h
// 入力受付に関するクラスの定義ファイル（実装は input_stream.cpp ）
#ifndef INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_ // 二重インクルード防止
#define INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_

#include "../base_info.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 先頭行がヘッダでない場合にコンストラクタの第二引数に与える値
const bool NO_HEADER = false ;

// デフォルトの入力ファイルの属性名
const string DEFAULT_LINE_HEADER = "ID,Mathematics,Science,English,Japanese,History,Geography" ;

// 出力の形式を表す文字列
const char* output_types = {
  "dropouts",
  "top-vs-bottom"
} ;

// デフォルトの区切り文字を表す定数
const char DEFAULT_DELIMITER = ',' ;

// InputStream クラスの定義
class InputStream {
protected:
  // メンバフィールド
  int data_num ;              // データ数
  string line_header ;        // 入力ファイルの先頭行
  vector<string> lines_data ; // 入力ファイルの2行目以降
  string output_type ;        // 出力の形式
public:
  // コンストラクタ
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

#endif // INPUT_STREAM_H_KAOVIAOEI892194_INCLUDED_
////////////////////////////////////////////////////////
