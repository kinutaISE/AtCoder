#include "base_info.h"
#include "stream/input_stream.h"
#include "student/student.h"
#include "stream/output_stream.h"
#include <iostream>

int main(int argc, char *argv[]) {
  InputStream istream(argv) ;
  StudentSet students(istream) ;
  OutputStream ostream(istream, students) ;
  ostream.output() ;
  return 0 ;
}
