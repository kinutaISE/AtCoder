#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std ;

const bool BLACK = false ;
const bool WHITE = true ;

void show_line(vector< pair<COLOR, int> > res) ;

int main(int argc, char *argv[]) {
  string line ;
  cin >> line ;

  vector< pair<bool, int> > result(2) ;
  result[0] = make_pair(BLACK, 1) ;
  result[1] = make_pair(WHITE, 1) ;

  bool turn = BLACK ;

  for (char c : line) {
    if (c == 'R') {

    }
    else {

    }
    turn = !turn ;
    if (!result[turn].second)
      result.erase(result[turn]) ;
  }

  show_line(result) ;

  return 0 ;
}

void show_line(vector< pair<COLOR, int> > res) {
  for (auto p : res) {
    for (int i = 1 ; i <= p.second ; i++)
      cout << ( (p.first == WHITE) ? "w" : "b" ) ;
  }
  cout << endl ;
}
