#include <iostream>
#include <vector>
using namespace std ;
using dptable = vector< vector< vector<int> > > ;

int N ;
int capacity_upper_bound ;
vector<int> capacities ;
vector<int> values ;

dptable table ;
vector< vector<int> > evaluations ;

void dynamic_programming_core(int k, int cub) {
  if (k == 0) {
    evaluations.at(0).at(cub) = 0 ;
    return ;
  }
  vector<int> &solution_nk = table.at(k - 1).at(cub) ;
  int &eval_nk = evaluations.at(k - 1).at(cub) ;
  if (eval_nk == -1)
    dynamic_programming_core(k - 1, cub) ;
  if (cub < capacities.at(k - 1)) {
    table.at(k).at(cub) = solution_nk ;
    evaluations.at(k).at(cub) = eval_nk ;
    return ;
  }
  int residual_cub = cub - capacities.at(k - 1) ;
  vector<int> &solution_k = table.at(k - 1).at(residual_cub) ;
  int &eval_k = evaluations.at(k - 1).at(residual_cub) ;
  if (eval_k == -1)
    dynamic_programming_core(k - 1, residual_cub) ;
  if (eval_nk < eval_k + values.at(k - 1)) {
    table.at(k).at(cub) = solution_k ;
    table.at(k).at(cub).push_back(k) ;
    evaluations.at(k).at(cub) = eval_k + values.at(k - 1) ;
    return ;
  }
  table.at(k).at(cub) = solution_nk ;
  evaluations.at(k).at(cub) = eval_nk ;
}

void dynamic_programming() {
  table = dptable(N + 1, vector< vector<int> >(capacity_upper_bound + 1)) ;
  evaluations = vector< vector<int> >(N + 1, vector<int>(capacity_upper_bound + 1)) ;
  for (int k = 0 ; k <= N ; k++) {
    for (int cub = 0 ; cub <= capacity_upper_bound ; cub++)
      evaluations.at(k).at(cub) = -1 ;
  }
  dynamic_programming_core(N, capacity_upper_bound) ;
}

void showOptimalSolution() {
  for (int v : table.at(N).at(capacity_upper_bound))
    cout << v << endl ;
}

int main() {

  cin >> N >> capacity_upper_bound ;
  capacities = vector<int>(N) ;
  values = vector<int>(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> capacities.at(i) >> values.at(i) ;

  dynamic_programming() ;

  showOptimalSolution() ;
}
