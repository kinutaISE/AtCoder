#include "classes/student.h"
#include "functions/functions_input.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

int main() {
  vector<Student> students ;
  accept_input(students) ;

  cout << "display infomation of students:" << endl ;

  for (Student& student : students)
    cout << student.get_info() << endl ;
}
