<?php
    $cad = "Contando palabras";
    /* Si no se incluye el formato, cuenta el número de palabras. */
    $numeroDePalabras = str_word_count($cad);
    $pal1 = str_word_count($cad,1);
    /* Se crea un vector con dos posiciones: pal1[0] conteniendo "Contando" y pal1[1] almacenando "palabras". */
    $pal2 = str_word_count($cad,2);
    /* Se crea un vector con dos posiciones: pal2[0] conteniendo "Contando" y pal2[9] almacenando "palabras". */
?>

