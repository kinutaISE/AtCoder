#include <iostream>

using namespace std ;

int linear_search(int A[], int k) ;

int main() {
  int A[] = {1, 2, 3} ;
  linear_search(A, 2) ;
}

int linear_search(int A[], int k) {
  int *it ;
  it = &A[0] ;
  cout << *it << endl ;
}