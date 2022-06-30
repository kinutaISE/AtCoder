<?php namespace Track ;

define('ERROR_CODE', -1) ;

function main($line)
{
  // 仕様に従った入力であるか判定
  if ( !validate_input($line) ) {
    // 仕様に従った入力でない場合
    // printf('%d', ERROR_CODE) ;
    // return 0 ;
    return ERROR_CODE ;
  }

  $ans = to_english($line) ;

  // printf('%s', ucfirst( implode(' ', $ans) )) ;
  return ucfirst( implode(' ', $ans) ) ;
}

function validate_input($line)
{
  // 空文字かどうか
  if ($line === '')
    return false ;
  // 数字または . 以外の文字が含まれているか
  $is_appeared_point = false ;
  for ($i = 0 ; $i < mb_strlen($line) ; $i++) {
    $c = substr($line, $i, 1) ;
    if ($c === '.') {
      if ($i === 0 || $is_appeared_point)
        return false ;
      $is_appeared_point = true ;
      continue ;
    }
    if ( !is_numeric($c) )
      return false ;
  }
  // 0 や 0.~ 以外で先頭が 0 でないか
  if ( substr($line, 0, 1) === '0' ) {
    return ($line === 0 || substr($line, 1, 1) === '.') ;
  }

  return true ;
}

function to_english($line)
{
  // 以下は仕様に従った入力であることを前提としたコード
  // 整数部分と小数部分に分ける
  $integer_part = $line ;
  $fractional_part ;
  if ( strpos($line, '.') !== false ) {
    $number = explode('.', $line) ;
    $integer_part = $number[0] ;
    $fractional_part = $number[1] ;
  }
  // 1000 ごとに切り出す
  $number_splited = array() ;
  $digit = 0 ;
  do {
    $digit++ ;
    $key = ($digit === 1) ? '' : (
      ($digit === 2) ? 'thousand' : 'billion'
    ) ;
    $number_splited[$key] = $integer_part % 1000 ;
    $integer_part /= 1000 ;
    $integer_part = floor($integer_part) ;
  } while ($integer_part > 0) ;

  // 1000 ごとに切り出した各部分を英語表記にする
  $ans = array() ;
  if ($digit === 3)
    $ans[] = to_english_less_1000($number_splited['billion']) . ' billion' ;
  if ($digit >= 2) {
    $str = to_english_less_1000($number_splited['thousand']) ;
    if ($str !== '')
      $ans[] = $str . ' thousand' ;
  }
  $ans[] =
    ($number_splited[''] === 0 && $digit === 1) ? 'zero' : to_english_less_1000($number_splited['']) ;

  // 小数点以下を英語表記にする
  if ( !empty($fractional_part) ) {
    $fractional_part = to_english_fractional($fractional_part) ;
    $ans[] = 'point ' . $fractional_part ;
  }

  return $ans ;
}

function to_english_less_1000($str)
{
  if ($str === 0)
    return '' ;
  // 0 以上 9 以下の場合
  if ($str <= 9)
    return to_english_one_digit($str) ;
  // 10 以上 19 以下の場合
  else if ($str <= 19)
    return to_english_two_digit($str) ;
  // それ以上 (20 以上 999 以下) の場合
  $res = array() ;
  if ($str >= 100)
    $res[] = to_english_one_digit( floor($str / 100) ) . ' hundred' ;
  $ten_digit = floor($str % 100 / 10) * 10 ;
  if ($ten_digit !== 0) {
    $res[] = to_english_10times($ten_digit) ;
    $one_digit = $str % 10 ;
    if ($one_digit !== 0)
      $res[] = to_english_one_digit($one_digit) ;
  }
  return implode(' ', $res) ;
}

function to_english_one_digit($str)
{
  switch ($str) {
    case 0:
      return 'zero' ;
    case 1:
      return 'one' ;
    case 2:
      return 'two' ;
    case 3:
      return 'three' ;
    case 4:
      return 'four' ;
    case 5:
      return 'five' ;
    case 6:
      return 'six' ;
    case 7:
      return 'seven' ;
    case 8:
      return 'eight' ;
    case 9:
      return 'nine' ;
  }
}

function to_english_two_digit($str)
{
  switch ($str) {
    case 10:
      return 'ten' ;
    case 11:
      return 'eleven' ;
    case 12:
      return 'twelve' ;
    case 13:
      return 'thirteen' ;
    case 14:
      return 'fourteen' ;
    case 15:
      return 'fifteen' ;
    case 16:
      return 'sixteen' ;
    case 17:
      return 'seventeen' ;
    case 18:
      return 'eighteen' ;
    case 19:
      return 'nineteen' ;
  }
}
function to_english_10times($str)
{
  switch ($str) {
    case 10:
      return 'ten' ;
    case 20:
      return 'twenty' ;
    case 30:
      return 'thirty' ;
    case 40:
      return 'forty' ;
    case 50:
      return 'fifty' ;
    case 60:
      return 'sixty' ;
    case 70:
      return 'seventy' ;
    case 80:
      return 'eighty' ;
    case 90:
      return 'ninety' ;
  }
}

function to_english_fractional($str)
{
  $res = array() ;
  for ($i = 0 ; $i < strlen( $str ) ; $i++)
    $res[] = to_english_one_digit( substr( $str, $i, 1) ) ;
  return implode(' ', $res ) ;
}
