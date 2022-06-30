<?php namespace Track ;

function main($item_num, $conspicuities)
{
  // 前提：すべての商品の目立ちやすさが異なる（部分点 2）
  // 目立ちやすさの昇順にソート
  $conspicuities = sort($conspicuities) ;
  // 同じ値の個数を持った配列に直す
  // $conspicuities_compressed = compress($conspicuities) ;
  // 自身以下の個数を数える
  // $counts = count_less_num($conspicuities_compressed) ;
  // 答えを求める
  $ans = 1 ;
  for ($i = 1 ; $i < $item_num ; $i++) {
    $ans += $i ;
  }
  return $ans % 100003 ;
}
function compress($conspicuities)
{
  // 前提：$conspicuities はソートされている
  $cs_compressed = array() ;
  $count = 0 ;
  $current = -1 ;
  foreach ($conspicuities as $conspicuity) {
    if ($conspicuity !== $current) {
      $cs_compressed[] = $count ;
      $current = $conspicuity ;
      $count = 1 ;
      continue ;
    }
    $count++ ;
  }
  return $cs_compressed ;
}
// function count_less_num($cs_compressed)
// {
//   $counts = array() ;
//   $prev = -1 ;
//   for ($i = 1 ; $i < )
//   return $counts ;
// }
