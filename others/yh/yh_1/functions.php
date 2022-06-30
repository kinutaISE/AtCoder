<?php namespace Track ;
// ファイルのタイプを返す関数
function get_filetype($filename)
{
  // 制約に従った入力であるかどうか
  if ( !validate_input($filename) )
    return 'Invalid Filename!' ;
  /*
  imgファイルであるかどうか
    yes : doc ファイルであるかどうか
      yes : presentation
      no : img
    no : doc ファイルであるかどうか
      yes : doc
      no : other
  */
  $type =
    is_image($filename) ?
      (is_document($filename) ? 'presentation' : 'image') :
      (is_document($filename) ? 'document' : 'other') ;
  return $type ;
}
// 制約を満たすファイル名であるかどうかの判定
function validate_input($filename)
{
  /*
  制約：
    - 1 文字以上 30 文字以下
    - すべての文字は「半角英数字」「半角ドット」「半角アンダーバー」からなる
  */
  if ( mb_strlen($filename) < 1 || mb_strlen($filename) > 30 )
    return false ;
  foreach ( str_split($filename) as $c ) {
    if (ctype_alnum($c) && $c !== '.' && $c !== '_')
      return false ;
  }
  return true ;
}
// img ファイルであるかどうかを判定する
function is_image($filename)
{
  return (strpos($filename, 'img') !== false) ;
}
// doc ファイルであるかどうかを判定する
function is_document($filename)
{
  return (strpos($filename, 'doc') !== false) ;
}
