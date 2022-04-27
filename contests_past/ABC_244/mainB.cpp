#include <iostream>
#include <utility>
#include <vector>

using namespace std ;

const pair<int, int> EAST_DIRECTION = make_pair(1, 0) ;
const pair<int, int> SOUTH_DIRECTION = make_pair(0, -1) ;
const pair<int, int> WEST_DIRECTION = make_pair(-1, 0) ;
const pair<int, int> NORTH_DIRECTION = make_pair(0, 1) ;

//vector < pair<int, int> > ds = {make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1)} ;
vector < pair<int, int> > ds = {EAST_DIRECTION, SOUTH_DIRECTION, WEST_DIRECTION, NORTH_DIRECTION} ;

void add_direction(pair<int, int>& current, int d) {
  current.first += ds[d].first ;
  current.second += ds[d].second ;
}

int main() {
  int order_num ;
  string orders ;
  cin >> order_num >> orders ;

  pair<int, int> current ;
  current.first = current.second = 0 ;
  int current_direction = 0 ;

  for (int i = 0 ; i < order_num ; i++) {
    char order = orders.at(i) ;
    if (order == 'S') {
      add_direction(current, current_direction) ;
      continue ;
    }
    current_direction++ ;
    current_direction %= 4 ;
  }
  cout << current.first << " " << current.second << endl ;
}
