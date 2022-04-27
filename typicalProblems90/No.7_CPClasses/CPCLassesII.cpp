#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {
  int class_num ;
  cin >> class_num ;
  vector<int> ratings_class(class_num) ;
  for (int i = 0; i < class_num ; i++)
    cin >> ratings_class.at(i) ;
  int student_num ;
  cin >> student_num ;
  vector<int> ratings_student(student_num) ;
  for (int i = 0; i < student_num ; i++)
    cin >> ratings_student.at(i) ;

  sort(ratings_class.begin(), ratings_class.end()) ;

  for (int rs : ratings_student) {
    if (rs <= *ratings_class.begin()) {
      cout << *ratings_class.begin() - rs << endl ;
      continue ;
    }
    if (rs >= *ratings_class.end()) {
      cout << rs - *ratings_class.end() << endl ;
      continue ;
    }
    auto right_it = lower_bound(ratings_class.begin(), ratings_class.end(), rs) ;
    auto left_it = right_it - 1 ;
    cout << min(rs - *left_it, *right_it - rs) << endl ;
  }
  return 0 ;
}
