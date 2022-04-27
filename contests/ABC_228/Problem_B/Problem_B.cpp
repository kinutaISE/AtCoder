# include <iostream>
# include <vector>
using namespace std ;

int main() {
  int N, X ;
  cin >> N >> X ;
  vector<int> seq(N + 1) ;
  for (int i = 1 ; i <= N ; i++)
    cin >> seq.at(i) ;

  vector<bool> is_known(N + 1) ;
  is_known.at(X) = true ;
  int succ = seq.at(X) ;
  int count = 1 ;
  while (! is_known.at(succ)) {
    is_known.at(succ) = true ;
    succ = seq.at(succ) ;
    count++ ;
  }
  cout << count << endl ;
}
