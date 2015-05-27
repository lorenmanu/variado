<?php
    error_reporting(E_ALL); # Se muestran los tres tipos.
    error_reporting(E_ALL & ~E_NOTICE); /* Se muestran errores y avisos, pero no
             notificaciones. */
    error_reporting(0); # No se muestra ningún tipo de error.
?>

