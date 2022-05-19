////////////////////////////////////////////////////////
// ./stream/output_stream.cpp
// 出力に関するクラスの実装（定義は output_stream.h ）

#include "output_stream.h"

using namespace std ;

// コンストラクタ
OutputStream::OutputStream(InputStream &in, StudentSet &ss) {
  istream = in ;
  students = ss ;
}

// メンバ関数
// 出力をする関数（output_dropouts() または output_top_vs_bottom() を呼び出す）
void output() const {
  switch (in.get_output_type()) {
    case "dropouts":
      output_dropouts() ;
      break ;
    case "top-vs-bottom":
      output_top_vs_bottom() ;
      break ;
  }
}
// 出力形式が dropouts の場合の出力をする関数
void output_dropouts() const {
  auto dropouts = students.get_dropout_students() ;

  cout << "ID" << endl ;
  for (Student &s : dropouts)
    cout << s.get_id() << endl ;
}
// 出力形式が top-vs-bottom の場合の出力をする関数
void output_top_vs_bottom() const {
  auto tops = students.get_top_students() ;
  auto bottoms = students.get_bottom_students() ;

  cout << "ID,Mean" << endl ;
  for (Student &s : bottoms)
    cout << s.get_id() << ',' << s.get_average() << endl ;
  for (Student &s : tops)
    cout << s.get_id() << ',' << s.get_average() << endl ;
}
////////////////////////////////////////////////////////
