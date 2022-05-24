#include "system/system.cpp"
#include <iostream>

using namespace std ;

int main(int argc, char *argv[]) {
  // 入力の受け取り
  vector<string> lines ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line);
    if (line == "") break ;
    lines.push_back(line) ;
  }

  // 入力をシステムに与える
  DeliverySystem ds(lines) ;

  // FIFOでシステムがクエリを処理する
  while (! ds.is_completed() )
    ds.process_top_query() ;

  return 0 ;
}
