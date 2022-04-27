#include <iostream>
#include <vector>
using namespace std ;

int main() {
  string s1, s2 ;
  cin >> s1 >> s2 ;

  if (s1.at(0) != '#' && s1.at(1) != '#') {
    cout << "Yes" << endl ;
    return 0 ;
  }

  int k = (s1.at(0) == '#') ? 0 : 1 ;
  if (k == 0) {
    if (s2.at(1) != '#')
      cout << "Yes" << endl ;
    else {
      if (s1.at(1) == '#' || s2.at(0) == '#')
        cout << "Yes" << endl ;
      else
        cout << "No" << endl ;
    }
  }
  else {
    if (s2.at(0) != '#')
      cout << "Yes" << endl ;
    else {
      if (s1.at(0) == '#' || s2.at(1) == '#')
        cout << "Yes" << endl ;
      else
        cout << "No" << endl ;
    }
  }
}
