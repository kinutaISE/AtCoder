<?php namespace Track ;
// 運賃に関する情報
define('FARE_INFO', [
  '初乗り' =>
    [
      '上限距離' => 1052, // 単位はメートル
      '運賃' => 410,
    ],
  '加算' =>
    [
      '更新距離' => 237, // 単位はメートル
      '運賃' => 80,
    ],
  '低速' =>
    [
      '上限速度' => 10, // 単位は km/h
      '更新時間' => 90, // 単位は秒
      '運賃' => 80,
    ],
  '深夜' =>
    [
      '開始時刻' => 22,
      '終了時刻' => 5,
      '割増率' => 1.25,
    ]
]) ;

require_once(__DIR__ . '/functions.php') ;
require_once(__DIR__ . '/FareCalculator.php') ;