#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
  int N ;
  cin >> N ;
  vector<int> diameters(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> diameters.at(i) ;

  sort(diameters.begin(), diameters.end()) ;

  int current_diameter ;
  int current_index = 0 ;
  int count = 0 ;
  while (true) {
    count++ ;
    current_diameter = diameters.at(current_index) ;
    int i ;
    for (i = current_index + 1 ; i < N ; i++) {
      if (diameters.at(i) != current_diameter)
        break ;
    }
    if (i == N)
      break ;
    current_index = i ;
  }

  cout << count << endl ;
}
