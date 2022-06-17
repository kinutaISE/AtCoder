<?php namespace Track;

require_once(__DIR__ . '/config.php') ;

function main($records) {
  // 入力が仕様に従うものであるかどうか
  if ( !validate_records($records) )
    exit(-1) ;
  // 運賃計算機をインスタンス化
  $fare_calculator = new FareCalculator($records) ;
  // 計算の実行
  $fare_calculator->process_all() ;
  // 結果の出力
  printf($fare_calculator->get_total_fere() . PHP_EOL) ;
  exit(0) ;
}

$records = array();
while (true) {
  $stdin = fgets(STDIN);
  if ($stdin == "") {
    break;
  }
  $records[] = rtrim($stdin);
}
main($records);
