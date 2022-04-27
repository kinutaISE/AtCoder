# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>
using namespace std ;

int main() {
  int N, K ;
  cin >> N >> K ;
  vector< pair<int, int> > data_si(N) ;
  for (int i = 0 ; i < N ; i++) {
    data_si.at(i).second = i ;
    int sum_i = 0 ;
    for (int j = 0 ; j < 3 ; j++) {
      int p_ij ;
      cin >> p_ij ;
      sum_i += p_ij ;
    }
    data_si.at(i).first = sum_i ;
  }

  sort(data_si.begin(), data_si.end()) ;

  int base_score = data_si.at(N - K).first ;
  vector<bool> result(N) ;
  for (pair<int, int> d_si : data_si)
    result.at(d_si.second) = (base_score <= d_si.first + 300) ;

  for (int i = 0 ; i < N ; i++) {
    if (result.at(i)) {
      cout << "Yes" << endl ;
      continue ;
    }
    cout << "No" << endl ;
  }
}
