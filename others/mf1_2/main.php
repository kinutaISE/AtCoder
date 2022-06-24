<?php namespace Track;

require_once('functions.php') ;
// 入力の受け取り
$line = rtrim( fgets(STDIN) ) ;

main($line) ;
