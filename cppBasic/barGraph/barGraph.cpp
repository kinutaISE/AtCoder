#include <iostream>
using namespace std;

int main() {
  int num_a, num_b ;
  cin >> num_a >> num_b ;

  // ここにプログラムを追記
  int count_a = 0 ;
  cout << "A:" ;
  while (count_a < num_a) {
    cout << "]" ;
    count_a++ ;
  }
  cout << endl ;

  int count_b = 0 ;
  cout << "B:" ;
  while (count_b < num_b) {
    cout << "]" ;
    count_b++ ;
  }
  cout << endl ;
}
