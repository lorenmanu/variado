<?php
    $nota = 3;
    if ($nota > 9 )
    {
        $mensaje = "Matricula de honor";
    }
    elseif ($nota < 9 and $nota >= 8 )
    {
        $mensaje = "Sobresaliente";
    }
    elseif ($nota < 8 and $nota >= 7 )
    {
        $mensaje = "Notable";
    }
    elseif ($nota <7 and $nota >= 5 )
    {
        $mensaje = "Aprobado";
    }
    else
    {
        $mensaje = "Suspenso!";
    }
    echo $mensaje,". \n";
    $moneda = "EURO";
    switch ( $moneda )
    {
        case "DOLLAR" :
            $cambio = 1.39;
            break;
        case "LIBRA" :
            $cambio = 0.75;
            break;
        default:
            $cambio = .5;
            break;
    }
    echo $moneda,". \n";
?>

