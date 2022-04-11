#include <iostream>
#include <vector>

using namespace std ;

bool contains(vector<int> list, int v) {
  for (int i = 0; i < list.size(); i++)
    if (list[i] == v) return true ;
  return false ;
}

int main() {
  int N ;
  cin >> N ;
  vector<int> list_a(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> list_a[i] ;
  vector<int> list_b(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> list_b[i] ;

  int count1 = 0 ;
  int count2 = 0 ;
  for (int i = 0 ; i < N ; i++) {
    if (contains(list_a, list_b[i])) {
      if (list_a[i] == list_b[i])
        count1++ ;
      else
        count2++ ;
    }
  }
  cout << count1 << endl ;
  cout << count2 << endl ;
}
