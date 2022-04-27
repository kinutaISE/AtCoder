#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int N, K ;
vector<char> sequence ;

vector<char> subsequence ;

void find_minimum_subsequence() {
  subsequence = vector<char>(K) ;
  for (int i = 0 ; i < K ; i++)
    subsequence.at(i) = sequence.at(i) ;

  int start_pos = 0 ;
  for (int i = 0 ; i < K ; i++) {
    char candidate = sequence.at(start_pos) ;
    for (int j = start_pos + 1 ; j <= N - K + i ; j++) {
      char c = sequence.at(j) ;
      if (candidate <= c)
        continue ;
      candidate = c ;
      start_pos = j ;
    }
    subsequence.at(i) = candidate ;
    start_pos++ ;
  }
}

int main() {
  cin >> N >> K ;
  string s ;
  cin >> s ;
  sequence = vector<char>(N) ;
  for (int i = 0 ; i < N ; i++)
    sequence.at(i) = s.at(i) ;

  find_minimum_subsequence() ;

  for (int i = 0 ; i < K ; i++)
    cout << subsequence.at(i) ;
  cout << endl ;
}
