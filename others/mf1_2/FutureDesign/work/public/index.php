<?php namespace Track;

require_once('functions.php') ;
// 入力の受け取り
//$line = rtrim( fgets(STDIN) ) ;

$lines = [
  0,
  1,
  12,
  1234,
  12341234,
  0.1,
  12.34,
  100.55,
] ;

?>

<!DOCTYPE HTML>

<ul>
  <?php foreach ($lines as $line):?>
    <li><?= $line . ' → ' . main($line) ;?></li>
  <?php endforeach ;?>
</ul>
