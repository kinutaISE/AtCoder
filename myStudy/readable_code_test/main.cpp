#include "structs/student.h"
#include "functions/functions_input.h"
#include <iostream>
#include <vector>

using namespace std ;

void show_students_info(const vector<Student> ss) {
  for (const Student& s : ss) {
    cout << "-------------------------------------" << endl ;
    s.show_info() ;
    cout << "-------------------------------------" << endl ;
  }
}

int main() {
  cout << "----- Test -----" << endl ;

  vector<Student>* students ;
  accept_input(students) ;

  show_students_info(*students) ;
}
