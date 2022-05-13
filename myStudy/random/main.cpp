#include "dice.h"
#include <iostream>
#include <ctime>

using namespace std ;

int main() {
  srand( (unsigned int) time(NULL) ) ;

  for (int i = 0 ; i < 10 ; i++)
    cout << dice() << endl ;
}
