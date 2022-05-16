////////////////////////////////////////////////////////////////
/*
./base_infomation.h
基本的な数値や科目名などを設定しておく
・科目数を表す定数
・科目名の一覧となるベクトル（中身はファイル読み込み時に格納）
・科目に対応する列挙体
・落第となる点数（科目ごとに異なることを考え配列とする）
*/
#ifndef BASE_H_IFBIAKFO7891234_INCLUDED_ // 二重インクルード防止
#define BASE_H_IFBIAKFO7891234_INCLUDED_

#include <vector>

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
  49
} ;

#endif // BASE_H_IFBIAKFO7891234_INCLUDED_
////////////////////////////////////////////////////////////////
