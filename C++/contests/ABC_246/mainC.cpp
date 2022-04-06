#include <iostream>
#include <cmath>
using namespace std ;

int main() {
  int merchandise_num, coupon_num, discount ;
  cin >> merchandise_num >> coupon_num >> discount ;
  int total = 0 ;
  for (int i = 0 ; i < merchandise_num ; i++) {
    int value ;
    cin >> value ;
    total += value ;
  }
  int using_num = min(coupon_num, total / discount) ;
  total -= discount * using_num ;
  cout << total << endl ;
}
