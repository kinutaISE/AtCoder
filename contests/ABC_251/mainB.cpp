#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

const int SELECTED_NUM_UB = 3 ;
int weight_num, total_upper_bound ;
vector<int> weights(weight_num) ;

int main() {
  cin >> weight_num >> total_upper_bound ;
  weights = vector<int> (weight_num) ;
  for (int i = 0 ; i < weight_num ; i++)
    cin >> weights[i] ;

  sort(weights.begin(), weights.end()) ;

  vector<bool> is_feasible(total_upper_bound + 1) ;
  int total = 0 ;
  for (int i = 0 ; i < weight_num ; i++) {

    total += weights[i] ;
    if (total > total_upper_bound) {
      total -= weights[i] ;
      break ;
    }
    is_feasible[total] = true ;

    for (int j = i + 1 ; j < weight_num ; j++) {
      total += weights[j] ;
      if (total > total_upper_bound) {
        total -= weights[j] ;
        break ;
      }

      is_feasible[total] = true ;

      for (int k = j + 1 ; k < weight_num ; k++) {

        total += weights[k] ;
        if (total > total_upper_bound) {
          total -= weights[k] ;
          break ;
        }

        is_feasible[total] = true ;
        total -= weights[k] ;

      }
      total -= weights[j] ;
    }
    total -= weights[i] ;
  }

  int solution_count = 0 ;
  for (bool b : is_feasible)
    solution_count += b ;

  cout << solution_count << endl ;
}
