#include <iostream>
#include <set>

using namespace std ;

int main() {
  int input_num ;
  cin >> input_num ;

  set<int> number_set ;
  for (int i = 0 ; i < input_num ; i++) {
    int v ;
    cin >> v ;
    number_set.insert(v) ;
  }

  cout << number_set.size() << endl ;
}
