// 文字列に関する種々の関数を定義（実装は functions_str.cpp）

#ifndef FUNCTION_STR_H_IBFUAIFU782184_INCLUDED_
#define FUNCTION_STR_H_IBFUAIFU782184_INCLUDED_

#include <iostream>
#include <vector>
#include <string>

// 文字列 str を区切り文字 del として分割する関数
vector<string> split(string str, char del) ;
// 文字列の配列 ss から特定の文字 str が入っているインデックスを返す（存在しない場合は -1 を返す）
int find(const char* ss[], string str) ;

#endif
