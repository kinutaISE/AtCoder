<?php namespace Track;

require_once('functions.php') ;

// ファイル名の取得
$filename = rtrim( fgets(STDIN) ) ;
// ファイルタイプの取得・出力
$filetype = get_filetype($filename);
printf('%s', $filetype) ;
