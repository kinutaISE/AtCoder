#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int class_num ;
vector<int> ratings_class ;
int student_num ;
vector<int> ratings_student ;

int lower_bound_index(int v, int l, int r) {
  // v <= ratings_class[i] となる最小の i を求める．
  if (l == r - 1) return r ;
  int mid = l + (r - l) / 2 ;
  if ( v >= ratings_class.at(mid) )
    return lower_bound_index(v, mid, l) ;
  return lower_bound_index(v, l, mid) ;
}
int lower_bound_index(int v) {
  if ( v <= *ratings_class.begin() ) return 0 ;
  if ( v >= *ratings_class.end() ) return class_num - 1 ;
  return lower_bound_index(v, 0, class_num - 1) ;
}

int main() {
  cin >> class_num ;
  set<int> ratings_class_set ;
  for (int i = 0 ; i < class_num ; i++) {
    int r ;
    cin >> r ;
    ratings_class_set.insert(r) ;
  }
  class_num = ratings_class_set.size() ;
  ratings_class = vector<int>(class_num) ;
  int pos = 0 ;
  for (int r : ratings_class_set) {
    ratings_class.at(pos) = r ;
    pos++ ;
  }
  cin >> student_num ;
  ratings_student = vector<int>(student_num) ;
  for (int j = 0 ; j < student_num ; j++)
    cin >> ratings_student.at(j) ;

  sort(ratings_class.begin(), ratings_class.end()) ;
  sort(ratings_student.begin(), ratings_student.end()) ;

  for (int rs : ratings_student) {
    int right = lower_bound_index(rs) ;
    if (right == 0) {
      cout << abs( rs - *ratings_class.begin() ) << endl ;
      continue ;
    }
    if (right == class_num - 1) {
      cout << abs( rs - *ratings_class.end() ) << endl ;
      continue ;
    }
    int left = right - 1 ;
    cout << min( abs( rs - ratings_class.at(right) ), abs( rs - ratings_class.at(left) ) ) << endl ;
  }
}
