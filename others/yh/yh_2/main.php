<?php namespace Track;

require_once('functions.php') ;

$line = rtrim( fgets(STDIN) ) ;
$participants_num = calculate_max_participants($line) ;

printf('%s', $participants_num) ;
