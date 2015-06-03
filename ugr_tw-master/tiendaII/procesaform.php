<?php  
    $mail = "";
    $password = "";
    $name = "";
    $apellido = "";
    $telefono = "";
    $fecha = "";

    $mail = $_POST["email"];
    $password = $_POST["password"];
    $name = $_POST["nombre"];    
    $apellido = $_POST["apellidos"];
    $telefono = $_POST["telf"];
    $fecha = $_POST["nacimiento"];
    echo "Enhorabuena $name !!<br/>";
    echo "<p>Los datos han sido guardados con exito.</p>";
    mysql_connect("localhost","x76440070","x76440070");// primero el host, segundo el user, tercero la contraseña
    mysql_select_db("db76440070");// hay ke seleccionar la base de datos o si no nunca te va a guardar

    mysql_query("SET NAMES 'utf8'");

    mysql_query("INSERT INTO usuarios(email,password,nombre,apellidos,telefono,fechanacimiento) VALUES ('$mail',MD5('$password'),'$name','$apellido','$telefono','$fecha')");  
      session_start();  
    $_SESSION['exito'] = "ok";
    header("Location: suscribir.php"); 
exit;
      
?>  

