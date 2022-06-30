<?php namespace Track ;
define('UPPER_BOUND', 1000000000) ;

// 1次会で満腹になる最小の人数を求める
function calculate_max_participants($line)
{
  // 制約を満たす入力であるか
  if ( !validate_input($line) )
    return 'Invalid Input!' ;

  // 入力の数値を分ける
  $input = split_line($line) ;

  $full_num =
    ( ceil( $input['sushi_num'] / $input['people_num'] ) < $input['capacity'] ) ?
      0 : $input['sushi_num'] % $input['people_num'] ;
  return $input['people_num'] - $full_num ;
}
function validate_input($line, $delim = ' ')
{
  /*
  制約
    - 3つの整数 n, m, k
    - すべて、1 以上 10^9 以下
    - n ≤ m * k ≤ 10^9
  */
  $splited_line = explode($delim, $line) ;
  if (count($splited_line) !== 3)
    return false ;
  foreach ($splited_line as $value) {
    if ( !is_numeric($value) )
      return false ;
    if ($value < 1 || $value > UPPER_BOUND)
      return false ;
  }
  return (
    $splited_line[1] * $splited_line[2] >= $splited_line[0]
    && $splited_line[1] * $splited_line[2] <= UPPER_BOUND
  ) ;
}
// 入力を「sushi_num（寿司の数）」「people_num（忘年会の参加人数）」「capacity（1人当たりが食べられる寿司の数）」にわける
function split_line($line, $delim = ' ')
{
  $splited_line = explode($delim, $line) ;
  $keys = ['sushi_num', 'people_num', 'capacity'] ;
  return array_combine($keys, $splited_line) ;
}
