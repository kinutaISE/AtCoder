#include "base_infomation.h"
#include "student/student.h"
#include "functions/functions_input.cpp"
#include "functions/functions_output.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  char* filename = argv[2] ;
  vector<Student> students ;
  accept_input(filename, ss) ;
  char* output_type = argv[1] ;
  if ( strcmp(output_type, "dropouts") )
    output_dropouts(ss, 2) ;
  else if ( strcmp(output_type, "top-vs-bottom") )
    output_top_vs_bottom(ss) ;
  return 0 ;
}
