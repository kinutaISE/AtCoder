#include <iostream>

using namespace std ;

int main() {
  int str_size ;
  string str ;
  cin >> str_size >> str ;

  cout << str.at(str_size - 1) << endl ;
}
