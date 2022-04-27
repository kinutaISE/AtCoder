#include <iostream>
#include <vector>
using namespace std ;

vector<string> split(string str, char del) {
  vector<string> result ;
  result.push_back("") ;
  int pos = 0 ;
  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result[pos] += c ;
  }
  return result ;
}

int main() {
  vector< vector<int> > coordinates ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    if (line == "")
      break ;
    auto data = split(line, ' ') ;
    vector<int> xy(2) ;
    xy[0] = stoi(data[0]) ;
    xy[1] = stoi(data[1]) ;
    coordinates.push_back(xy) ;
  }
  cout << (coordinates[0][0] ^ coordinates[1][0] ^ coordinates[2][0]) << " " << (coordinates[0][1] ^ coordinates[1][1] ^ coordinates[2][1]) << endl ;
}
