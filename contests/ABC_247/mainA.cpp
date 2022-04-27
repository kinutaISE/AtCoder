#include <iostream>
using namespace std;

int main() {
  string str ;
  cin >> str ;
  cout << '0' ;
  for (int i = 0 ; i < 3 ; i++)
    cout << str.at(i) ;
  cout << endl ;
}
