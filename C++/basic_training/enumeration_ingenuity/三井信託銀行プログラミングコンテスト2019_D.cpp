#include <iostream>
#include <vector>

using namespace std ;

bool contains(vector<int> nums, string str) {
  int pos = 0 ;
  for (char c : str) {
    int k = int(c - '0') ;
    if (k != nums[pos]) continue ;
    pos++ ;
    if (pos > 2) return true ;
  }
  return false ;
}

int main() {
  int digit_num ;
  string str ;
  cin >> digit_num >> str ;

  int ans = 0 ;
  for (int a = 0 ; a <= 9 ; a++) {
    for (int b = 0 ; b <= 9 ; b++) {
      for (int c = 0 ; c <= 9 ; c++) {
        vector<int> candidate{a, b, c} ;
        if (contains(candidate, str)) ans++ ;
      }
    }
  }

  cout << ans << endl ;
}
