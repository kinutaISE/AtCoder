<?php namespace Track ;

require_once('config.php') ;

function minimization_planting_count()
{
  // 入力を受け取る（各行を要素としてもつ配列）
  $lines = array() ;
  while (true) {
    $line = rtrim( fgets(STDIN) ) ;
    if ($line == '')
      break ;
    $lines[] = $line ;
  }

  // 入力が制約を満たすかどうかの判定
  if ( !validate_input($lines) )
    return 'Invalid Input!' ;
  /*
  入力の受け取り
    - 入力の形式：
      n k
      string
      - n：草むらの長さ
      - k：芝植え機が連続して植えることができる長さ
      - string：草むらの初期状態
  */

  // 入力を分解し、変数に代入
  $first_line_splited = explode(' ', $lines[0]) ;
  $grass_length = $first_line_splited[0] ; // 草むらの長さ(n)
  $planting_length = $first_line_splited[1] ; // 芝植え機が連続して植えることができる長さ(k)
  $grass_status = $lines[1] ; // 草むらの初期状態(string)

  // 貪欲法による探索
  $planting_count = greedy($grass_length, $planting_length, $grass_status) ;

  // 求めた芝植えの回数を返す
  return $planting_count ;
}
// 入力が制約を満たすかの判定
function validate_input($lines)
{
  // 入力が2行であるか
  if ( count($lines) != 2 )
    return false ;
  /*
  1 行目が正しい入力であるか
    - 形式：n k
      - n は 2 ≤ n ≤ 100000 を満たす整数
      - k は 1 ≤ k ≤ n を満たす整数
  */
  // 空白を区切り文字として 1 行目を分割
  $first_line_splited = explode(' ', $lines[0]) ;
  // 空白 1 つで区切られているか
  if ( count($first_line_splited) != 2 )
    return false ;
  // 区切られた各文字が整数であるか
  for ($i = 0 ; $i < 2; $i++) {
    if (
      !is_numeric($first_line_splited[$i])
      || ( strpos($first_line_splited[$i], '.') !== false )
    )
      return false ;
  }
  // n は 2 ≤ n ≤ 100000 を満たす整数 を満たすか
  if (
    $first_line_splited[0] < GRASS_LENGTH_LB
    || $first_line_splited[0] > GRASS_LENGTH_UB
  )
    return false ;
  // k は 1 ≤ k ≤ n を満たす整数 を満たすか
  if (
    $first_line_splited[1] < PLANTING_LENGTH_LB
    || $first_line_splited[1] > $first_line_splited[0]
  )
    return false ;
  /*
  2 行目が正しい入力であるか
    - 形式：string
      - 長さは n
      - 「w」と「.」のみからなる文字列
  */
  // 長さは n を満たすか
  if ( mb_strlen($lines[1]) != $first_line_splited[0] )
    return false ;
  // 「w」と「.」のみからなる文字列か
  foreach ( mb_str_split($lines[1]) as $character ) {
    if ($character !== 'w' && $character !== '.')
      return false ;
  }
  // 全ての条件を満たすため正しい出力であることを返す
  return true ;
}
// 貪欲法によって芝植えの最小回数を求める関数
function greedy($grass_length, $planting_length, $grass_status)
{
  $pos = 0 ; // 現在の探索位置
  $count = 0 ; // 芝植えの回数

  // 片側から草の生えていない箇所を探索する
  while ( $pos < $grass_length ) {
    // $pos[m] 地点の芝の状態を取得する
    $pos_status = substr($grass_status, $pos, 1) ;

    // 草が生えていた場合、1[m]先へ
    if ($pos_status === 'w') {
      $pos++ ;
      continue ;
    }

    // 生えていなかった場合、その地点から芝植えを行う
    $count++ ;
    // 次の開始地点は $planting_length[m] 先とする
    $pos += $planting_length ;
  }

  // 芝植えの回数を返す
  return $count ;
}
