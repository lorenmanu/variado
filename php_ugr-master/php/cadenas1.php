<?php
    $nombre = "Juan";
    $var1 = "$nombre";
    $var2 = '$nombre';
    echo $var1,"\n";
    echo $var2,"\n";
    $cad1 = "­ Cadena entre\n\tcomillas dobles ­ ";
    $cad2 = '­ Cadena entre\n\tcomillas simples ­ ';
    echo $cad1,"\n";
    echo $cad2,"\n";
    $numero = 10;
    $cad1 = "­ Hay '$numero' personas en la cola. ­ ";
    $cad2 = '­ Hay "$numero" personas esperando. ­';
    echo $cad1,"\n";
    echo $cad2;
?>

