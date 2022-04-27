#include <iostream>

using namespace std ;

int main() {
	string str ;
  cin >> str ;
  int residual = 45 ;
  for (char c : str)
    residual -= int(c) - int('0') ;
  cout << residual << endl ;
}
