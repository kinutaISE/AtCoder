#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

vector<bool> make_is_prime(int64_t n) {
  vector<bool> is_prime(n + 1, true) ;
  is_prime[0] = false ;
  is_prime[1] = false ;
  for (int64_t i = 2; i * i <= n ; i++) {
    if (! is_prime[i]) continue;
    for (int64_t j = i * i ; j <= n ; j += i)
      is_prime[j] = false ;
  }
  return is_prime ;
}

int main() {
  int64_t N ;
  cin >> N ;

  int64_t upper_bound = int64_t( cbrt(N / 2.0) ) ;
  auto is_prime = make_is_prime(upper_bound) ;

  vector<int64_t> prime_numbers ;
  for (int64_t k = 2 ; k <= upper_bound ; k++)
    if (is_prime[k]) prime_numbers.push_back(k) ;

  int64_t count = 0 ;
  for (int64_t i = 0 ; i < prime_numbers.size() ; i++) {
    int64_t p = prime_numbers[i] ;
    for (int64_t j = i + 1 ; j < prime_numbers.size() ; j++) {
      int64_t q = prime_numbers[j] ;
      int64_t k = p * q * q * q ;
      if (k > N) break ;
      count++ ;
    }
  }

  cout << count << endl ;
}
