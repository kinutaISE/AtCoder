#include "base_infomation.h"
#include "input_stream/input_stream.h"
#include <iostream>

using namespace std ;

int main(int argc, char *argv[]) {
  InputStream istream(argv[2]) ;

  istream.show_input() ;

  return 0 ;
}
