#include <iostream>
#include <string>
#include <cmath>

using namespace std ;

// コールドゲームとなる点差
const int COLD_DIFF = 10 ;

// ゲーム終了時のメッセージ
const string MESSAGE_END = "game set" ;
// ゲーム継続時のメッセージ
const string MESSAGE_CONTINUE = "continue" ;

// 点差を判定する関数
bool is_game_set(int a, int b) {
  return abs(a - b) >= COLD_DIFF ;
}

int main(int argc, char *argv[]) {
  int score_a ;
  int score_b ;
  cin >> score_a >> score_b ;

  cout <<
    ( is_game_set(score_a, score_b) ? MESSAGE_END : MESSAGE_CONTINUE )
  << endl ;
}
