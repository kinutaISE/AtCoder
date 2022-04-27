#include <iostream>
using namespace std ;

int main() {
  int takahasi_h, takahasi_m ;
  int aoki_h, aoki_m ;
  cin >> takahasi_h >> takahasi_m >> aoki_h >> aoki_m ;

  if (takahasi_h < aoki_h)
    cout << "Takahashi" << endl ;
  else if (takahasi_h == aoki_h) {
    string output = (takahasi_m <= aoki_m) ? "Takahashi" : "Aoki" ;
    cout << output << endl ;
  }
  else
    cout << "Aoki" << endl ;
}
