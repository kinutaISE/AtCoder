#include <iostream>
#include <vector>

using namespace std ;

int student_num, music_num ;
vector< vector<int64_t> > scores ;

int64_t calc_total_score(int j_1, int j_2) {
  int64_t total = 0 ;
  for (int i = 0 ; i < student_num ; i++)
    total += max(scores[i][j_1], scores[i][j_2]) ;
  return total ;
}

int main() {
  cin >> student_num >> music_num ;
  scores = vector< vector<int64_t> >( student_num, vector<int64_t>(music_num) ) ;
  for (int i = 0 ; i < student_num ; i++) {
    for (int j = 0 ; j < music_num ; j++)
      cin >> scores[i][j] ;
  }

  int64_t best_total_score = 0 ;
  for (int j_1 = 0 ; j_1 < music_num - 1 ; j_1++) {
    for (int j_2 = j_1 + 1 ; j_2 < music_num ; j_2++)
      best_total_score = max(best_total_score, calc_total_score(j_1, j_2)) ;
  }

  cout << best_total_score << endl ;
}
