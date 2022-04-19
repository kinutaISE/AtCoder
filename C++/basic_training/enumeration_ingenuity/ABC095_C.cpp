#include <iostream>
#include <map>
#include <cmath>

using namespace std ;

int main() {
  map<string, long long> piza_values ;
  cin >> piza_values["A"] >> piza_values["B"] >> piza_values["AB"] ;
  long long requirement_A, requirement_B ;
  cin >> requirement_A >> requirement_B ;

  long long upper_bound = max(2 * requirement_A, 2 * requirement_B) ;
  long long min_value = (piza_values["A"] + piza_values["AB"]) * requirement_A + (piza_values["B"] + piza_values["AB"]) * requirement_B ;
  for (long long ab = 0 ; ab <= upper_bound ; ab += 2) {
    long long a = max(0ll, requirement_A - (ab / 2)) ;
    long long b = max(0ll, requirement_B - (ab / 2)) ;
    long long value = piza_values["A"] * a + piza_values["B"] * b + piza_values["AB"] * ab ;
    min_value = min(min_value, value) ;
  }

  cout << min_value << endl ;
}
