#include <iostream>
#include <vector>
using namespace std ;

int break_num, total_length, select_num ;
vector<int> lengths ;

int main() {
  cin >> break_num >> total_length ;
  cin >> select_num ;
  select_num++ ;
  vector<int> points(break_num) ;
  for (int &p : points)
    cin >> p ;
  lengths = vector<int>(break_num + 1) ;
  lengths.at(0) = points.at(0) ;
  for (int i = 1 ; i < break_num ; i++)
    lengths.at(i) = points.at(i) - points.at(i - 1) ;
  lengths.back() = total_length - points.back() ;

  
}
