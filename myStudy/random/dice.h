#include <cstdlib>

int dice() {
  return ( 6.0 * rand() ) / (RAND_MAX + 1.0) + 1 ;
}
