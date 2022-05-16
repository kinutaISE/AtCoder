#include <iostream>
#include <string>

using namespace std ;

const int TARGET_LENGTH = 6 ;

int main() {
  string str ;
  cin >> str ;

  int repeat_num = TARGET_LENGTH / str.length() ;

  for (int i = 1 ; i <= repeat_num ; i++)
    cout << str ;
  cout << endl ;
}
