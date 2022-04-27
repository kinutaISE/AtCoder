#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std ;

int64_t N ;
int64_t A, B ;
int64_t P, Q ;
int64_t R, S ;

bool condition1(int64_t i, int64_t j) {
  int64_t lower_bound = max(1 - A, 1 - B) ;
  int64_t upper_bound = min(N - A, N - B) ;
  for (int k = lower_bound ; k <= upper_bound ; k++) {
    if (i == A + k && j == B + k)
      return true ;
  }
  return false ;
}
bool condition2(int64_t i, int64_t j) {
  int64_t lower_bound = max(1 - A, B - N) ;
  int64_t upper_bound = min(N - A, B - 1) ;
  for (int k = lower_bound ; k <= upper_bound ; k++) {
    if (i == A + k && j == B - k)
      return true ;
  }
  return false ;
}

int main() {
  cin >> N >> A >> B >> P >> Q >> R >> S ;

  for (int64_t i = P ; i <= Q ; i++) {
    string str ;
    for (int64_t j = R ; j <= S ; j++)
      str += (condition1(i, j) || condition2(i, j)) ? "#" : "." ;
    cout << str << endl ;
  }
}
