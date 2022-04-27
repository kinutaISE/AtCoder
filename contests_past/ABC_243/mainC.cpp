#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

const int RIGHT = 0 ;
const int LEFT = 1 ;

struct Person {
  int64_t start_x ;
  int64_t start_y ;
  int direction ;
  Person() {}
  Person(int64_t x, int64_t y, char d) {
    start_x = x ;
    start_y = y ;
    direction = (d == 'L') ;
  }
  bool operator < (const Person &p) const {
    return start_y < p.start_y ;
  }
} ;

int main() {
  int N ;
  cin >> N ;
  vector< vector<int64_t> > xy(N, vector<int64_t>(2)) ;
  for (int i = 0 ; i < N ; i++)
    cin >> xy[i][0] >> xy[i][1] ;
  string str ;
  cin >> str ;
  vector<Person> people(N) ;
  for (int i = 0 ; i < N ; i++)
    people[i] = Person(xy[i][0], xy[i][1], str.at(i)) ;

  sort(people.begin(), people.end()) ;
  int64_t current_y = 0 ;
  int64_t min_right = pow(10, 9) ;
  int64_t max_left = 0 ;
  for (Person p : people) {
    if (current_y != p.start_y) {
      current_y = p.start_y ;
      min_right = pow(10, 9) ;
      max_left = 0 ;
    }
    if (p.direction == RIGHT)
      min_right = min(min_right, p.start_x) ;
    else
      max_left = max(max_left, p.start_x) ;
    if (max_left > min_right) {
      cout << "Yes" << endl ;
      return 0 ;
    }
  }
  cout << "No" << endl ;
}
