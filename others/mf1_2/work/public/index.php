<?php namespace Track;

require_once('functions.php') ;
// 入力の受け取り
//$line = rtrim( fgets(STDIN) ) ;

$lines = [
  0,
  1,
  12,
  100,
  888,
  999,
  1000,
  1234,
  12341234,
  0.1,
  12.34,
  100.55,
  100000999.53214,
  'aaa',
  '',
  '0055',
  '111a111',
  '5..5',
  '.45'
] ;

?>

<!DOCTYPE HTML>

<ul>
  <?php foreach ($lines as $line):?>
    <li><?= $line . ' → ' . main($line) ;?></li>
  <?php endforeach ;?>
</ul>
