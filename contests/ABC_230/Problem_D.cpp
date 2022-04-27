#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std ;

int N, D ;
vector< pair<int, int> > intervals ;

set time_set ;
vector<int> times ;
vector< vector<int> > table ;

void dynamic_programming_core(int k, int t) {
  
}
void dynamic_programming() {
  sort(intervals.begin(), intervals.end()) ;
  for (int i = 0 ; i < intervals.size() ; i++)
    time_set.insert(intervals.at(i)) ;
  time_set.insert(0) ;
  while (! time_set.empty()) {
    int max = *rbegin(time_set) ;
    times.push_back(max) ;
    time_set.erase(max) ;
  }
  table = vector< vector<int> >(N + 1, vector<int>(times.size())) ;

}

int main() {
  cin >> N >> D ;
  intervals = vector< pair<int, int> >(N) ;
  for (int i = 0 ; i < N ; i++)
    cin >> intervals.at(i).first >> intervals.at(i).second ;



}
