#include <iostream>
#include <vector>
using namespace std ;

int N ;

vector<int> abc ;
int pair_num ;

void bt_count(int i, int p) {
  if (i == 3) {
    pair_num += N / p ;
    return ;
  }
  for (int k = abc.at(i - 1) ; ; k++) {
    int bound = p ;
    for (int j = i ; j < 4 ; j++)
      bound *= k ;
    if (bound > N)
      return ;
    abc.at(i) = k ;
    bt_count(i + 1, p * k) ;
  }
}
void bt_count() {
  abc = vector<int>(4) ;
  abc.at(0) = 1 ;
  bt_count(1, 1) ;
}

int main() {
  cin >> N ;

  bt_count() ;
  cout << pair_num << endl ;
}
