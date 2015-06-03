<?php
    mysql_connect('localhost','x76440070','x76440070')or die ('Ha fallado la conexión: '.mysql_error());
    mysql_select_db('db76440070')or die ('Error al seleccionar la Base de Datos: '.mysql_error());

    $usuario = $_POST["email"];   
    $password = $_POST["password"];

    $result = mysql_query("SELECT * FROM usuarios WHERE email = '$usuario'");

    //Validamos si el nombre del administrador existe en la base de datos o es correcto
    if($row = mysql_fetch_array($result))
    {     
    //Si el usuario es correcto ahora validamos su contraseña
        if($row["password"] == MD5($password))
        {
            //Creamos sesión
            session_start();  
            //Almacenamos el nombre de usuario en una variable de sesión usuario
            $_SESSION['usuario'] = $usuario;
            $nombre = $row['nombre'];
            $_SESSION['nombre'] = $nombre;  
            //Redireccionamos a la pagina: index.php
            header("Location: index.php");  
        }
        else
        {
            //En caso que la contraseña sea incorrecta enviamos un msj y redireccionamos a login.php
            ?>
            <script languaje="javascript">
            alert("Contraseña Incorrecta");
            location.href = "index.php";
            </script>
            <?php
                
        }
    }
    else
    {
        //en caso que el nombre de administrador es incorrecto enviamos un msj y redireccionamos a login.php
        ?>
        <script languaje="javascript">
        alert("El nombre de usuario es incorrecto!");
        location.href = "index.php";
        </script>
        <?php   
    }
    mysql_free_result($result);
    mysql_close();
?>
