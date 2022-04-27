#include <iostream>
#include <vector>
#include <utility>
using namespace std ;

int get_index(vector< pair<string, int> > ccs, string c) {
	for (int i = 0 ; i < ccs.size() ; i++) {
    	auto cc = ccs.at(i) ;
    	if (cc.first == c) return i ;
    }
  	return -1 ;
}

int main() {
	int N ;
  	cin >> N ;
  	vector< pair<string, int> > candidate_count(0) ;
    int size = 0 ;
  	for (int i = 0 ; i < N ; i++) {
      	string c ;
      	cin >> c ;
    	  int index = get_index(candidate_count, c) ;
      	if (index == -1) {
          auto cc = make_pair(c, 1) ;
        	candidate_count.push_back(cc) ;
          size++ ;
        	continue ;
        }
      	candidate_count.at(index).second++ ;
    }
  	string c = candidate_count.at(0).first ;
  	int max_vote = candidate_count.at(0).second ;
  	for (int i = 1 ; i < candidate_count.size() ; i++) {
      auto cc = candidate_count.at(i) ;
    	if (max_vote >= cc.second)
          continue ;
      c = cc.first ;
      max_vote = cc.second ;
    }
    cout << c << endl ;
}
