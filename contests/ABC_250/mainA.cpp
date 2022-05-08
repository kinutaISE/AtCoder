#include <iostream>

using namespace std ;

int main() {
  int H, W ;
  cin >> H >> W ;
  int R, C ;
  cin >> R >> C ;

  int adj_num = min(2, H) + min(2, W) ;
  if (R == 1 || R == H)
    adj_num-- ;
  if (C == 1 || C == W)
    adj_num-- ;

  cout << adj_num << endl ;
}
