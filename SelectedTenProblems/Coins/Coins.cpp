#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

vector<int> coin_nums(3) ;
int X ;

vector<int> values(3) ;
int pay_count ;
vector<int> bounds(3) ;

void bt_count(int k, int r) {
  if (k == 2) {
    if (r > bounds.at(2))
      return ;
    if (r % 50 != 0)
      return ;
    pay_count++ ;
    return ;
  }
  if (r > bounds.at(k))
    return ;
  int upper_bound = min(r / values.at(k), coin_nums.at(k)) ;
  int value = values.at(k) ;
  int residual = r - upper_bound * value ;
  for (int i = upper_bound ; i > -1 ; i--) {
    bt_count(k + 1, residual) ;
    residual += value ;
  }
}
void bt_count() {
  values.at(0) = 500 ;
  values.at(1) = 100 ;
  values.at(2) = 50 ;
  bounds.at(2) = 50 * coin_nums.at(2) ;
  bounds.at(1) = bounds.at(2) + 100 * coin_nums.at(1) ;
  bounds.at(0) = bounds.at(1) + 500 * coin_nums.at(0) ;
  bt_count(0, X) ;
}

int main() {
  for (int &num : coin_nums)
    cin >> num ;
  cin >> X ;

  bt_count() ;

  cout << pay_count << endl ;
}
