<?php 
    $consolasFavoritas = ""; 
    $comunicaciones = ""; 
    if ( isset( $_POST["consolasFavoritas"] ) ) { 
        foreach ( $_POST["consolasFavoritas"] as $consola ) { 
            $consolasFavoritas .= $consola . ", "; 
        } 
        // También se podría acceder mediante $_POST["consolasFavoritas"][0], 
        // $_POST["consolasFavoritas"][1] y $_POST["consolasFavoritas"][2].
        } 
    if ( isset( $_POST["comunicaciones"] ) ) { 
        foreach ( $_POST["comunicaciones"] as $comunicacion ) { 
            $comunicaciones .= $comunicacion . ", "; 
        }
    }
    echo "$consolasFavoritas <br/> $comunicaciones <br/>";
?>

