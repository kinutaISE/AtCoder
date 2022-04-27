#include <iostream>
#include <vector>
using namespace std ;

int N, declared_amount ;

int main() {
  cin >> N >> declared_amount ;

  declared_amount /= 1000 ;
  vector<int> bills(3) ;
  bills.at(0) = 10 ;
  bills.at(1) = 5 ;
  bills.at(2) = 1 ;
  vector<int> solution(3) ;

  int residual_amount = declared_amount ;
  int residual_num = N ;
  for (int i = 0 ; i < 3 ; i++) {
    int bill = bills.at(i) ;
    solution.at(i) = min(residual_num, residual_amount / bill) ;
    residual_num -= solution.at(i) ;
    residual_amount -= bill * solution.at(i) ;
  }
  if (residual_amount != 0) {
    cout << -1 << ' ' << -1 << ' ' << -1 << endl ;
    return 0 ;
  }
  for (int i = 0 ; i < 2 ; i++)
    cout << solution.at(i) << ' ' ;
  cout << solution.back() << endl ;
}

/*
using solution = vector<int> ;
vector< vector< solution > > table ;
vector< vector<int> > table_eval ;

void dynamic_programming_core(int k, int r) {
  if (k == 0 || r == 0) {
    table.at(k).at(r) = vector<int>(3) ;
    table_eval.at(k).at(r) = 0 ;
    return ;
  }

  int k_minus_1 = k - 1 ;
  vector<solution> &table_k_minus_1 = table.at(k_minus_1) ;

  if (r < 1) return ;
  int residual_1 = r - 1 ;
  int &eval_1 = table_eval.at(k_minus_1).at(residual_1) ;
  if (eval_1 == -1)
    dynamic_programming_core(k_minus_1, residual_1) ;
  solution subsolution_1 = table_k_minus_1.at(residual_1) ;

  if (r < 5) return ;
  int residual_5 = r - 5 ;
  int &eval_5 = table_eval.at(k_minus_1).at(residual_5) ;
  if (eval_5 == -1)
    dynamic_programming_core(k_minus_1, residual_5) ;
  solution subsolution_5 = table_k_minus_1.at(residual_5) ;

  if (r < 10) return ;
  int residual_10 = r - 10 ;
  int &eval_10 = table_eval.at(k_minus_1).at(residual_10) ;
  if (eval_10 == -1)
    dynamic_programming_core(k_minus_1, residual_10) ;
  solution subsolution_10 = table_k_minus_1.at(residual_10) ;

  int max_type = 0 ;
  solution opt_subsolution = table_k_minus_1.at(residual_1) ;
  int max_eval = eval_1 + 1 ;
  if (max_eval < eval_5 + 5) {
    max_type = 1 ;
    opt_subsolution = table_k_minus_1.at(residual_5) ;
    max_eval = eval_5 + 5 ;
  }
  if (max_eval < eval_10 + 10) {
    max_type = 2 ;
    opt_subsolution = table_k_minus_1.at(residual_10) ;
    max_eval = eval_10 + 10 ;
  }

  opt_subsolution.at(max_type)++ ;
  table.at(k).at(r) = opt_subsolution ;
  table_eval.at(k).at(r) = max_eval ;
}
void dynamic_programming() {
  table = vector< vector< solution > >(N + 1, vector<solution>(declared_amount + 1) ) ;
  table_eval = vector< vector<int> >(N + 1, vector<int>(declared_amount + 1) ) ;
  for (int k = 0 ; k <= N ; k++) {
    for (int r = 0 ; r <= declared_amount ; r++)
      table_eval.at(k).at(r) = -1 ;
  }
  dynamic_programming_core(N, declared_amount) ;
}
void show_result() {
  solution optimal_solution = table.at(N).at(declared_amount) ;
  int total_amount = optimal_solution.at(0) ;
  total_amount += 5 * optimal_solution.at(1) ;
  total_amount += 10 * optimal_solution.at(2) ;
  if (total_amount != declared_amount) {
    cout << -1 << ' ' << -1 << ' ' << -1 << endl ;
    return ;
  }
  for (int i = 2 ; i > 0 ; i--)
    cout << optimal_solution.at(i) << ' ' ;
  cout << optimal_solution.front() << endl ;
}

int main() {
  cin >> N >> declared_amount ;
  declared_amount /= 1000 ;

  dynamic_programming() ;

  show_result() ;
}
*/
