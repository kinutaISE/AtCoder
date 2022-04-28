#include <iostream>
#include <vector>
#include <sstream>

using namespace std ;

void show_matrix(vector< vector<int> > matrix) {
  // ostringstream os ; ← ここに書くと、各行の文字列が蓄積されてしまう
  for (int i = 0 ; i < matrix.size() ; i++) {
    ostringstream os ;
    auto row = matrix[i] ;
    copy(row.begin(), row.end(), ostream_iterator<int>(os, ",")) ;
    string s = os.str() ;
    cout << "[" << i << "] " << s.erase(s.size() - 1) << endl ;
  }
}

int main(int argc, char** argv) {
  int line_count = 0 ;
  string line ;
  vector< vector<int> > matrix ;
  while ( ! cin.eof() ) {
    getline(cin, line) ;
    if (line_count == 0)
      matrix = vector< vector<int> >( stoi(line) ) ;
    else {
      stringstream line_ss(line) ;
      string data_s ;
      while ( getline(line_ss, data_s, ' ') )
        matrix[ line_count - 1 ].push_back( stoi(data_s) ) ;
    }
    line_count++ ;
    cout << "line_count: " << line_count << endl ;
  }

  show_matrix(matrix) ;
}
