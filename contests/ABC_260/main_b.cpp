#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std ;

bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first  < right.first;
  }
}

int main() {
  // 入力の受け取り
  int n, x, y, z ;
  cin >> n >> x >> y >> z ;
  vector< pair<int, int> > math_scores ;
  vector< pair<int, int> > total ;
  for (int i = 0 ; i < n ; i++) {
    int s ;
    cin >> s ;
    math_scores.push_back( make_pair(s, i + 1) ) ;
    total.push_back( make_pair(s, i + 1) ) ;
  }
  vector< pair<int, int> > eng_scores ;
  for (int i = 0 ; i < n ; i++) {
    int s ;
    cin >> s ;
    eng_scores.push_back( make_pair(s, i + 1) ) ;
    total[i].first += s ;
  }
  // 本体
  vector<int> passed_indices ;
  // 数学の点数
  sort(math_scores.begin(), math_scores.end(), asc_desc) ;
  reverse(math_scores.begin(), math_scores.end()) ;
  for (int k = 0 ; k < x ; k++) {
    auto p = math_scores[k] ;
    passed_indices.push_back(p.second) ;
  }
  // 英語の点数
  sort(eng_scores.begin(), eng_scores.end(), asc_desc) ;
  reverse(eng_scores.begin(), eng_scores.end()) ;
  int eng_count = 0 ;
  int pos = -1 ;
  while (eng_count < y) {
    pos++ ;
    auto p = eng_scores[pos] ;
    if ( count(passed_indices.begin(), passed_indices.end(), p.second) > 0 )
      continue ;
    passed_indices.push_back(p.second) ;
    eng_count++ ;
  }
  // 数学と英語の合計
  sort(total.begin(), total.end(), asc_desc) ;
  reverse(total.begin(), total.end()) ;
  int total_count = 0 ;
  pos = -1 ;
  while (total_count < z) {
    pos++ ;
    auto p = total[pos] ;
    if ( count(passed_indices.begin(), passed_indices.end(), p.second) > 0 )
      continue ;
    passed_indices.push_back(p.second) ;
    total_count++ ;
  }
  // 結果の表示
  sort(passed_indices.begin(), passed_indices.end()) ;
  for (int ind : passed_indices)
    cout << ind << endl ;
  return 0 ;
}