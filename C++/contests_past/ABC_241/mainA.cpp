#include <iostream>
#include <vector>

using namespace std ;

int main() {
  vector<int> a(10) ;
  for (int i = 0 ; i < 10 ; i++)
    cin >> a[i] ;

  int current = a[0] ;
  for (int i = 0 ; i < 2 ; i++)
    current = a[current] ;

  cout << current << endl ;
}
