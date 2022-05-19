////////////////////////////////////////////////////////
// ./stream/output_stream.h
// 出力に関するクラスの定義ファイル（実装は output_stream.cpp ）

#ifndef OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_ // 二重インクルード防止
#define OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_

#include "../base_info.h"
#include "input_stream.h"
#include <iostream>
#include <vector>

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

#endif // OUTPUT_STREAM_H_KAICOAO18939_INCLUDED_
////////////////////////////////////////////////////////
