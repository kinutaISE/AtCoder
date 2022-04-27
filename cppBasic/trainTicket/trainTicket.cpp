#include <iostream>
#include <vector>
using namespace std ;

vector<int> numbers ;
int operator_num ;
vector<char> correct_operators ;
vector<char> operators ;

void display_formulation() {
  for (int i = 0 ; i < operators.size() ; i++) {
    cout << numbers.at(i) << correct_operators.at(i) ;
  }
  cout << numbers.back() << "=7" << endl ;
}

void backtracking(int i, int res) {
  if (i == operator_num) {
    if (res != 7)
      return ;
    correct_operators = operators ;
    return ;
  }

  int v = numbers.at(i + 1) ;

  operators.at(i) = '+' ;
  backtracking(i + 1, res + v) ;

  operators.at(i) = '-' ;
  backtracking(i + 1, res - v) ;
}

int main() {
  string numbers_str ;
  cin >> numbers_str ;

  for (char c : numbers_str)
    numbers.push_back( (int)c - 48 ) ;

  operator_num = numbers.size() - 1 ;
  correct_operators = vector<char>(operator_num) ;
  operators = vector<char>(operator_num) ;

  backtracking(0, numbers.at(0)) ;

  display_formulation() ;
}
