#include <iostream>
using namespace std ;

int get_area(int a, int b) {
  return 4 * a * b + 3 * a + 3 * b ;
}

bool is_wrong(int es) {
  for (int a = 1 ; a <= es ; a++) {
    for (int b = 1 ; b <= es ; b++) {
      int area = get_area(a, b) ;
      if (es == area)
        return false ;
    }
  }
  return true ;
}

int main() {
  int N ;
  cin >> N ;

  int count = 0 ;
  for (int i = 0 ; i < N ; i++) {
    int estimation ;
    cin >> estimation ;
    count += is_wrong(estimation) ;
  }

  cout << count << endl ;
}
