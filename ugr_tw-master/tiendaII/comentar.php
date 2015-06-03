<?php
/****************************************
**establecemos conexion con el servidor.
**nombre del servidor: localhost.
**Nombre de usuario: x76440070.
**Contraseña de usuario: x76440070.
**Si la conexion fallara mandamos un msj 'ha fallado la conexion'**/
mysql_connect('localhost','x76440070','x76440070')or die ('Ha fallado la conexión: '.mysql_error());

/*Luego hacemos la conexión a la base de datos. 
**De igual manera mandamos un msj si hay algun error*/
mysql_select_db('db76440070')or die ('Error al seleccionar la Base de Datos: '.mysql_error());


mysql_query("SET NAMES 'utf8'");

$mail = '';
$comentario = '';
$modelo = '';
if (!session_id())
    session_start();
$mail = $_SESSION['usuario'];
$comentario = $_POST['comentario'];
$modelo = $_POST['modelo'];
$tipo = $_POST['tipo'];

mysql_query("INSERT INTO comentario(usuario,comentario,modelo) VALUES ('$mail','$comentario','$modelo')");  

header("Location: producto.php?modelo=$modelo&tipo=$tipo"); 
//Mysql_free_result() se usa para liberar la memoria empleada al realizar una consulta
mysql_free_result($result);

/*Mysql_close() se usa para cerrar la conexión a la Base de datos y es 
**necesario hacerlo para no sobrecargar al servidor, bueno en el caso de
**programar una aplicación que tendrá muchas visitas ;) .*/
mysql_close();
?>
