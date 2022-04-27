#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <algorithm>

using namespace std ;

const int LENGTH = 30 ;
vector< vector<int> > tile(LENGTH, vector<int>(LENGTH)) ;
vector< vector<int> > directions{
  {1, 0, -1, -1},
  {3, -1, -1, 0},
  {-1, -1, 3, 2},
  {-1, 2, 1, -1},
  {1, 0, 3, 2},
  {3, 2, 1, 0},
  {2, -1, 0, -1},
  {-1, 3, -1, 1},
} ;
vector<int> di{0, -1, 0, 1} ;
vector<int> dj{-1, 0, 1, 0} ;
void set_input() {
  for (int i = 0 ; i < LENGTH ; i++) {
    string line ;
    cin >> line ;
    for (int j = 0 ; j < LENGTH ; j++) {
      tile[i][j] = int( line[j] - '0' ) ;
    }
  }
}

// vector< vector<int> > tile_status(LENGTH, vector<bool>(LENGTH)) ;
// const int UNDISCOVERED = 0 ;
// const int DISCOVERED = 1 ;
// const int PROCESSED = 2 ;
// vector< vector<int> > ans(LENGTH, vector<int>(LENGTH)) ;
// pair<int, int> calc_start() {
//   for (int i = 0 ; i < LENGTH ; i++) {
//     for (int j = 0 ; j < LENGTH ; j++) {
//       if (tile_status[i][j] == UNDISCOVERED)
//         return make_pair(i, j) ;
//     }
//   }
//   return make_pair(-1, -1) ;
// }
// void greedy() {
//   auto s = calc_start() ;
//   while (s.first != -1) {
//
//     s = calc_start() ;
//   }
// }

vector<int> rotate(vector<int> d, int k) {
  for (int dd = 0 ; dd <= 3 ; dd++) {
    d[dd] += di[k] % 4 ;
    d[dd] += dj[k] % 4 ;
  }
  return d ;
}

int main() {
  set_input() ;

  random_device rnd;     // 非決定的な乱数生成器を生成
  mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
  uniform_int_distribution<> rnd3(0, 3);

  // for (int k = 0 ; k < LENGTH * LENGTH ; k++)
  //   cout << rnd3(mt) ;
  // cout << endl ;

  vector<int> ans(LENGTH * LENGTH) ;

  for (int i = 0 ; i < LENGTH ; i++) {
    for (int k = 0 ; k <= 3 ; k++) {
      auto d = rotate(directions[ tile[i][0] ], k) ;
      if (d[2] != -1 && d[2] != 0)
        ans[30 * i] = k ;
    }
  }

  for (int j = 0 ; j < LENGTH ; j++) {
    for (int k = 0 ; k <= 3 ; k++) {
      auto d = rotate(directions[ tile[0][j] ], k) ;
      if (d[3] != -1 && d[3] != 1)
        ans[j] = k ;
    }
  }

  for (int i = 0 ; i < LENGTH / 2 ; i++) {
    for (int j = 0 ; j < LENGTH / 2 ; j++) {
      int best = 0 ;
      for (int k = 0 ; k <= 3 ; k++) {
        auto d = rotate(directions[ tile[0][j] ], k) ;
        int count = 0 ;
        for (int out : d) {
          if (out == 3 || out == 2)
            count++ ;
        }
        if (count <= best) continue ;
        best = count ;
        ans[j] = k ;
      }
    }
  }

  for (int i = 0 ; i < LENGTH / 2 ; i++) {
    for (int j = LENGTH / 2 ; j < LENGTH ; j++) {
      int best = 0 ;
      for (int k = 0 ; k <= 3 ; k++) {
        auto d = rotate(directions[ tile[0][j] ], k) ;
        int count = 0 ;
        for (int out : d) {
          if (out == 1 || out == 2)
            count++ ;
        }
        if (count <= best) continue ;
        best = count ;
        ans[j] = k ;
      }
    }
  }

  for (int i = LENGTH / 2 ; i < LENGTH ; i++) {
    for (int j = 0 ; j < LENGTH / 2 ; j++) {
      int best = 0 ;
      for (int k = 0 ; k <= 3 ; k++) {
        auto d = rotate(directions[ tile[0][j] ], k) ;
        int count = 0 ;
        for (int out : d) {
          if (out == 0 || out == 3)
            count++ ;
        }
        if (count <= best) continue ;
        best = count ;
        ans[j] = k ;
      }
    }
  }

  for (int i = LENGTH / 2 ; i < LENGTH ; i++) {
    for (int j = LENGTH / 2 ; j < LENGTH ; j++) {
      int best = 0 ;
      for (int k = 0 ; k <= 3 ; k++) {
        auto d = rotate(directions[ tile[0][j] ], k) ;
        int count = 0 ;
        for (int out : d) {
          if (out == 0 || out == 1)
            count++ ;
        }
        if (count <= best) continue ;
        best = count ;
        ans[j] = k ;
      }
    }
  }

  for (int ij = 0 ; ij < LENGTH * LENGTH ; ij++)
    cout << ans[ij] ;
  cout << endl ;
}
