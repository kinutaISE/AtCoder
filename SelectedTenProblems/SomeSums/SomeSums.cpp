#include <iostream>
#include <vector>
using namespace std ;

int N ;
int lb, ub ;

vector<int> digit_sums ;
vector<int> subsummations ;

void set_dist_sums() {
  digit_sums = vector<int>(N + 1) ;
  for (int k = 0 ; k <= N ; k++) {
    int temp = k ;
    int &ds_k = digit_sums.at(k) ;
    while (temp > 0) {
      ds_k += temp % 10 ;
      temp /= 10 ;
    }
  }
}

int main() {
  cin >> N ;
  cin >> lb >> ub ;

  set_dist_sums() ;

  int sum = 0 ;
  for (int k = 1 ; k <= N ; k++) {
    if (digit_sums.at(k) < lb)
      continue ;
    if (digit_sums.at(k) > ub)
      continue ;
    sum += k ;
  }

  cout << sum << endl ;
}
