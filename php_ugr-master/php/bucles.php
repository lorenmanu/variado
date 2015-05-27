<?php
    /* Bucle for */
    for($i=1;$i<=9;$i++)
    {
    echo "\nTabla del multiplicar del $i \n";
    for($j=1;$j<=9;$j++)
    {
    $result = $i * $j;
    echo "<p>$i x $j = $result<p>\n";
    }
    }
    /* Bucle while */
    $fruta = array ( "naranja", "manzana", "uvas" );
    $encontrada = "no";
    $k = 0;
    while ( $encontrada != "si" )
    {
    if ($fruta[$k] == "manzana" )
    {
    $encontrada = "si";
    echo "manzana\n";
    }
    else
     
      echo "$fruta[$k] no es una manzana\n";
    $k++;
    }
    /* Bucle do... while */
    $encontrada = "no";
    $k = 0;
    do
    {
    PHP 5 – Práctica 4 de Tecnologías Web – 12/15
    Tecnologías Web
    Grado en Ingeniería Informática
    Práctica 4: PHP 5
    if ($fruta[$k] == "manzana" )
    {
    $encontrada = "si";
    echo "manzana\n";
    }
    else
     
      echo "$fruta[$k] no es una manzana\n";
    $k++;
    } while ( $encontrada != "si" )
?>
