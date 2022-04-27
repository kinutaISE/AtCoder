#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
  int N ;
  cin >> N ;
  vector<int> cards(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> cards.at(i) ;

  sort(cards.begin(), cards.end()) ;

  int score_alice = cards.back() ;
  for (int i = N - 3 ; i > -1 ; i -= 2)
    score_alice += cards.at(i) ;
  int score_bob = cards.at(N - 2) ;
  for (int i = N - 4 ; i > -1 ; i -= 2)
    score_bob += cards.at(i) ;

  cout << score_alice - score_bob << endl ;
}
