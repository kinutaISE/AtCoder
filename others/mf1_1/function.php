<?php namespace Track ;

function main($line)
{
  /*
    石の状態を管理する変数の定義
      - $stone_status['L'] : 左側にある石の個数(amount)と色(color)を保管
      - $stone_status['R'] : 左側にある石の個数(amount)と色(color)を保管
  */
  $stone_status = [
    'L' => [
      'amount' => 1,
      'color' => 'black'
    ],
    'R' => [
      'amount' => 1,
      'color' => 'white'
    ]
  ] ;

  // 棋譜に従って以下の処理を行う
  for ($turn = 0 ; $turn < strlen($line) ; $turn++) {
    // どちら（黒 or 白）のターンであるか
    $current_color = ($turn % 2 === 0) ? 'black' : 'white' ;
    // 棋譜を取り出す
    $side = substr($line, $turn, 1) ;

    // 打った場所の隣の色を取得する
    $residual_color = $stone_status[$side]['color'] ;

    // 隣の色によって場合分け：
    if ($current_color === $residual_color) {
      // 打った側と同じ色の場合
      // 個数を追加する
      $stone_status[$side]['amount']++ ;
    }
    else {
      // 打った側と異なる色の場合
      // 逆側の指定文字(L or R)を取得する
      $side_other = ($side === 'L') ? 'R' : 'L' ;
      // 逆側の石の数が 0 個かどうかで場合分け：
      if ($stone_status[$side_other]['amount'] > 0) {
        // 0 個でない場合
        // 違う色の側をひっくり返す
        $turned_over_num = $stone_status[$side]['amount'] ;
        $stone_status[$side_other]['amount'] += ($turned_over_num + 1) ;
        $stone_status[$side]['amount'] = 0 ;
      }
      else {
        // 0 個の場合
        // 位置を入れ替えて1にする
        $stone_status = swap($stone_status) ;
        $stone_status[$side]['amount']++ ;
      }
    }
  }

  // 結果を表示する
  show_result($stone_status) ;
}

function swap($ss)
{
  list($ss['L'], $ss['R']) = array($ss['R'], $ss['L']) ;
  return $ss ;
}

function show_result($ss)
{
  // 黒石の数を取得する
  $black_num =
    ($ss['L']['color'] === 'black') ? $ss['L']['amount'] : $ss['R']['amount'] ;
  // 白石の数を取得する
  $white_num =
    ($ss['L']['color'] === 'white') ? $ss['L']['amount'] : $ss['R']['amount'] ;
  // 結果の表示
  printf('%d %d', $black_num, $white_num) ;
}
