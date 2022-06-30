<?php namespace Track;

require_once('functions.php') ;

$item_num = rtrim( fgets(STDIN) ) ;
$conspicuities = explode( ' ', rtrim( fgets(STDIN) ) ) ;
printf('%d', main($item_num, $conspicuities)) ;
