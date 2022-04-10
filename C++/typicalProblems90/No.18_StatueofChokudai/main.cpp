#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std ;

int T, L, X, Y ;
double omega ;

vector<double> get_coordinates(int e) {
  vector<double> xyz(3) ;
  xyz[0] = 0.0 ;
  double theta = 3 * M_PI_2 - omega * e ;
  xyz[1] = L / 2.0 * cos(theta) ;
  xyz[2] = L / 2.0 * ( 1 + sin(theta) ) ;
  return xyz ;
}

double calculate_angle(vector<double> xyz) {
  return atan2( xyz[2] ,sqrt( pow(X, 2) + pow(Y - xyz[1], 2) ) ) ;
}

int main() {
  cout << fixed << setprecision(10) ;

  cin >> T >> L >> X >> Y ;
  omega = 2 * M_PI / T ;
  int Q ;
  cin >> Q ;
  for (int i = 0 ; i < Q ; i++) {
    int e ;
    cin >> e ;
    auto xyz = get_coordinates(e) ;
    double theta = calculate_angle(xyz) ;
    cout << 180 * theta / M_PI << endl ;
  }
}
