#include <iostream>

using namespace std ;

const int ARRAY_SIZE = 10 ;

void show(const int array[]) ;

int main() {
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
  show(array) ;
}

void show(const int array[]) {
  for (int i = 0 ; i < ARRAY_SIZE ; i++)
    cout << array[i] << ' ' ;
  cout << endl ;
}
