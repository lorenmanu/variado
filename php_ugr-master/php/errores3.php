<?php
    if ( /* Condición */)
       {
          error_log("Se ha producido un error en la condición",3,"/temp/err_log");
          /* O incluso enviar al administrador un mensaje de correo electrónico: */
          error_log("Se ha producido un error en la condición",1,"admin@midominio.es");
          exit();
       }
?>

