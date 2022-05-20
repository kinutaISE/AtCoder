#include "person/person.cpp"
#include <iostream>

int main() {
  Person p("Tarou", 17) ;
  AdultPerson ap("Jirou", 22) ;

  p.func() ;
  ap.func() ;

  return 0 ;
}
