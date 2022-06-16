<?php
// 入力が適切であるかどうかの判定 ///////////////////////////////////
// 仕様に従った入力であるかどうかを返す
function validate_records($records)
{
  /*
  入力形式が正しいか
    - 2行以上のデータが含まれる
    - 1カラム目が時刻（hh:mm:ss.fff（文字列））
      - hh の上限は 99
    - 2カラム目が距離
      - 0.0 ~ 99.9
      - 必ず . を含み、小数点以下の桁数は 1
  */
  if ( count($records) < 2 )
    return false ;
  foreach ($records as $record) {
    $splited_record = explode(' ', $record) ;
    if (! is_time_str($splited_record[0]) )
      return false ;
    if (! is_dist_str($splited_record[1]) )
      return false ;
  }

  // 一行目が初乗りレコードになっているか
  $splited_record = explode(' ', $records[0]) ;
  if ($splited_record[1] !== '0.0')
    return false ;

  // レコードが時間軸順に並んでいるか
  for ($i = 1 ; $i < count($records) ; $i++) {
    $previous_record = $records[$i - 1] ;
    $current_record = $records[$i] ;
    if ( !is_before($previous_record, $current_record) )
      return false ;
  }
  return true ;
}
// 2つのレコードが時刻順になっているかを判定する
function is_before($pre_record, $succ_record) {
  $splited_pre_record = explode(' ', $pre_record) ;
  $splited_succ_record = explode(' ', $succ_record) ;
  $seconds_pre = get_seconds($splited_pre_record[0]) ;
  $seconds_succ = get_seconds($splited_succ_record[0]) ;
  return $seconds_pre < $seconds_succ ;
}
// 文字列が距離の形式になっているのかどうかを判定する
function is_dist_str($str)
{
  return preg_match('/^([1-9][0-9]{0,1}|0)(\.[0-9]{1,1})?$/', $str) ;
}
// 文字列が hh:mm:ss.fff（文字列）形式の時刻であるかどうかを判定する
function is_time_str($str)
{
  return isMatch_HHMMSS($str) ;
}
// 正規表現による時刻形式のチェック
function isMatch($pattern, $text, $errorIfEmpty = TRUE, &$matches = array()) {
  // 空文字チェック
  if ($text == '')
      return !$errorIfEmpty;
  return !preg_match($pattern, $text, $matches) ;
}
function isMatch_HHMMSS($text, $decimal = 0, $delim = ':', $errorIfEmpty = TRUE) {
  // 空文字チェック
  if ($text == '')
    return !$errorIfEmpty;

  $pattern = '/^(0[0-9]{1}|1{1}[0-9]{1}|2{1}[0-3]{1})' . $delim . '(0[0-9]{1}|[1-5]{1}[0-9]{1})' . $delim . '(0[0-9]{1}|[1-5]{1}[0-9]{1})';

  // 小数部があればパターンに追加
  if ($decimal > 0)
    $pattern = $pattern . sprintf('\.([0-9]{%d})', $decimal);
  $pattern = $pattern . '$/';

  return isMatch($pattern, $text, $errorIfEmpty);
}
function testisMatch_HHMMSS($time, $decimal = 0, $delim = ':'){
  return isMatch_HHMMSS($time, $decimal, $delim) ;
}
// hh:mm:ss.fff（文字列）形式で受け取った時刻を時・分・秒にわけて返す
function split_time($time)
{
  $keys = ['時', '分', '秒'] ;
  $splited_time = array_combine(
    $keys, explode(':', $time)
  ) ;
  return $splited_time ;
}
// 時刻を上限を 23:59:59.999 とした時刻に直して返す関数（文字列）
function remake_time($time)
{
  // 前提：入力時刻 は hh:mm:ss:fff（文字列）形式
  // 時・分・秒にわけた配列を受け取る
  $splited_time = remake_time_splited($time) ;
  return implode(':', $splited_time) ;
}
// 時刻を上限を 23:59:59.999 とした時刻に直して返す関数（配列）
function remake_time_splited($time)
{
  // 前提：入力時刻 は hh:mm:ss:fff（文字列）形式
  // 時・分・秒にわけた配列を受け取る
  $splited_time = split_time($time) ;
  $splited_time['時'] %= 24 ;
  return $splited_time ;
}
// 時刻に関する処理 //////////////////////////////////////////
// 受け取った時刻が深夜時間帯であるかどうかを返す
function is_midnight($time)
{
  // 時刻は hh:mm:ss.fff（文字列）形式で受け取る
  // 時刻を時・分・秒にわけた配列に変換（上限は 23:59:59.999）
  $splited_time = remake_time_splited($time) ;
  /*
  深夜時間帯であるかどうか
    - 00:00:00.000 ~ 04:59:59.999
    - 22:00:00.000 ~ 23:59:59.999
  */
  $is_midnight =
    ($splited_time['時'] < FARE_INFO['深夜']['終了時刻']) ||
    ($splited_time['時'] >= FARE_INFO['深夜']['開始時刻']) ;
  return $is_midnight ;
}
// 受け取った時刻を秒単位で数値化した値を返す
function get_seconds($time)
{
  // 時刻は hh:mm:ss.fff（文字列）形式で受け取る
  // 時・分・秒にわけた配列に変換
  $splited_time = split_time($time) ;
  // 求める秒数を計算・返す
  $seconds =
    $splited_time['時'] * 3600
    + $splited_time['分'] * 60
    + $splited_time['秒'] ;
  return $seconds ;
}
// 受け取った2つの時刻の差を返す（単位は秒）
function time_diff($time_a, $time_b)
{
  // 秒単位で数値化した値を計算
  $time_a_sec = get_seconds($time_a) ;
  $time_b_sec = get_seconds($time_b) ;
  // それらの差を返す
  return abs($time_a_sec - $time_b_sec) ;
}
// 速度を返す（単位は km / h）
function get_speed($time_a, $time_b, $distance)
{
  // 前提：距離 $distance はメートル単位
  // 時刻 $time_a から時刻 $time_b の間で $distance 進んだ平均速度が低速かどうか
  // 2つの時刻の差を求める（単位は時間）
  $time_diff_hour = time_diff($time_a, $time_b) / 3600 ;
  // 距離をキロメートル単位に直す
  $distance_km = $distance / 1000 ;
  // 速度を計算・返す
  $speed = $distance_km / $time_diff_hour ;
  return $speed ;
}
// 低速であるかどうか
function is_lowspeed($time_a, $time_b, $distance)
{
  // 前提：距離 $distance はメートル単位
  // 速度（単位は km/h ）を計算する
  $speed = get_speed($time_a, $time_b, $distance) ;
  // 速度が低速かどうかを判定・結果を返す
  $is_lowspeed = ($speed <= FARE_INFO['低速']['上限速度']) ;
  return $is_lowspeed ;
}
