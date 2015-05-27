<?php
    $numero=12321.666;
    /* Formatea el número con dos decimales y '.' y ',' como separadores decimales y miles */
    echo number_format($numero,2),”<br/>”;
    /* Formatea el número con 2 decimales y con el ',' y de decimales  y la '.' de miles */
    echo number_format($numero,2,",","."); 
?>

