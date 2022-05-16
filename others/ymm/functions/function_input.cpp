////////////////////////////////////////////////////////////////
/*
./functions/functions_input.cpp
入力の受け取りに関する関数の実装をする
*/
#ifndef INPUT_CPP_DKIABIAK781847_INCLUDED_ // 二重インクルード防止
#define INPUT_CPP_DKIABIAK781847_INCLUDED_

#include "../base_infomation.cpp"
#include "functions_str.cpp"
#include "../student/student.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std ;

// filename をもつファイルから入力を受け取り、学生のベクトル ss に格納する
void accept_input(char* filename, vector<Student>& ss) {
  fstream file = filename(filename, ios::in) ;

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
}

#endif // INPUT_CPP_DKIABIAK781847_INCLUDED_
////////////////////////////////////////////////////////////////
