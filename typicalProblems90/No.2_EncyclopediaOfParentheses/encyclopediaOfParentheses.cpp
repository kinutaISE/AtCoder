#include <iostream>
#include <vector>
using namespace std ;

int N ;

vector<char> parentheses ;

void display_parentheses() {
  for (char p : parentheses)
    cout << p ;
  cout << endl ;
}
void enumerate_correct_parentheses(int k, int rlc) {
  if (k == N) {
    display_parentheses() ;
    return ;
  }

  int residual_num = N - k ;

  if (residual_num == rlc) {
    for (int i = k ; i < N ; i++)
      parentheses.at(i) = ')' ;
    display_parentheses() ;
    return ;
  }

  if (residual_num < rlc)
    return ;

  parentheses.at(k) = '(' ;
  enumerate_correct_parentheses(k + 1, rlc + 1) ;

  if (rlc == 0)
    return ;
  
  parentheses.at(k) = ')' ;
  enumerate_correct_parentheses(k + 1, rlc - 1) ;
}
void enumerate_correct_parentheses() {
  if (N % 2 == 1)
    return ;
  parentheses = vector<char>(N) ;
  parentheses.at(0) = '(' ;
  enumerate_correct_parentheses(1, 1) ;
}

int main() {
  cin >> N ;

  enumerate_correct_parentheses() ;
}
