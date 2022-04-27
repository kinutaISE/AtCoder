#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N ;
vector<string> dp_table ;

void calculate_sk_core(int k) {
  if (k == 1) {
    dp_table[k] = "1" ;
    return ;
  }
  if (dp_table[k - 1] == "")
    calculate_sk_core(k - 1) ;
  dp_table[k] = dp_table[k - 1] + " " + to_string(k) + " " + dp_table[k - 1] ;
}

void calculate_sk() {
  dp_table = vector<string>(N + 1) ;
  calculate_sk_core(N) ;
}

int main() {
  cin >> N ;
  calculate_sk() ;
  cout << dp_table[N] << endl ;
}
