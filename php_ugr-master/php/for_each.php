<?php
    $vectorPoblaciones = array ( "ES" => 34501130, "FR" => 5494423, "CH" => 333472867);
    ksort($vectorPoblaciones);
    foreach($vectorPoblaciones as $nacion => $poblacion )
    {
        $poblacion = number_format($poblacion);
        echo "$nacion: $poblacion.<br/>";
    }
    /* Si se utilizara foreach tal que así:
    foreach($vectorPoblaciones as $poblacion)
     {...}
        se almacenan sólo los valores en la variable $población sucesivamente. */
?>
