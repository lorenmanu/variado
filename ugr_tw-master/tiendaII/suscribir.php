<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Práctica Evaluable I TW</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta name="description" content="">
  <meta name="author" content="">

	<!--link rel="stylesheet/less" href="less/bootstrap.less" type="text/css" /-->
	<!--link rel="stylesheet/less" href="less/responsive.less" type="text/css" /-->
	<!--script src="js/less-1.3.3.min.js"></script-->
	<!--append ‘#!watch’ to the browser URL, then refresh the page. -->
	
	<link href="css/bootstrap.min.css" rel="stylesheet">
	<link href="css/style.css" rel="stylesheet">

  <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
  <!--[if lt IE 9]>
    <script src="js/html5shiv.js"></script>
  <![endif]-->

  <!-- Fav and touch icons -->
  <link rel="apple-touch-icon-precomposed" sizes="144x144" href="img/apple-touch-icon-144-precomposed.png">
  <link rel="apple-touch-icon-precomposed" sizes="114x114" href="img/apple-touch-icon-114-precomposed.png">
  <link rel="apple-touch-icon-precomposed" sizes="72x72" href="img/apple-touch-icon-72-precomposed.png">
  <link rel="apple-touch-icon-precomposed" href="img/apple-touch-icon-57-precomposed.png">
  <link rel="shortcut icon" href="img/favicon.png">
  
	<script type="text/javascript" src="js/jquery.min.js"></script>
	<script type="text/javascript" src="js/bootstrap.min.js"></script>
	<script type="text/javascript" src="js/scripts.js"></script>

<?php
        if (!session_id())
            session_start();
?>
</head>

<body>
<div class="container">
	<div class="row clearfix">
		<div class="col-md-12 column">
			<div class="page-header" align="center">
				<h1>
					Tienda de informática
				</h1>
			</div>
			<nav class="navbar navbar-default" role="navigation">
				<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
					<ul class="nav navbar-nav">
						<li>
							<a href="index.php">Portada</a>
						</li>
						<li>
							<a href="portatiles.php">Portátiles</a>
						</li>
						<li>
							<a href="sobremesa.php">Sobremesa</a>
						</li>
						<li>
							<a href="componentes.php">Componentes</a>
						</li>
					</ul>
					<form class="navbar-form navbar-left" role="search">
						<div class="form-group">
							<input type="text" class="form-control">
						</div> <button type="submit" class="btn btn-default">Buscar</button>
					</form>
					<ul class="nav navbar-nav navbar-right">
                        <li class="active">
                            <a href="suscribir.php">Suscribirse</a>
                        </li>
<?php
    if(!isset($_SESSION['usuario'])) 
    {
?>
                    <li class="dropdown">
					    <a href="#" class="dropdown-toggle" data-toggle="dropdown">Login<strong class="caret"></strong></a>
							<ul class="dropdown-menu">
                                <li>
                                    <form role="form" action="validar_usuario.php" method="post">
                                        <div class="form-group">
                                            Usuario:
                                            <input type="email" class="form-control" id="email" name="email" required="required"  />
                                        </div>
                                        <div class="form-group">
                                            Password:<input type="password" class="form-control" id="password" name="password"  />
                                        </div>
                                        <input name="iniciar" class="btn btn-default" type="submit" value="Login" />
                                    </form>
                                </li>
        					</ul> 
						</li>
                    
<?php
    }else{
?>
                    <li class="dropdown">
                        <a href="#" class="dropdown-toggle" data-toggle="dropdown">
<?php
    echo $_SESSION['usuario'];
?>
                            <strong class="caret"></strong></a>
							<ul class="dropdown-menu">
                            <li>
                                <a href="#">Ver perfil</a>
                            </li>
                                <li>
                                    <form role="form" action="logout.php" method="post">
                                    <input name="salir" class="btn btn-default" type="submit" value="Logout" />
                                    </form>
                                </li>
        					</ul> 
						</li>
<?php
    }
?>     
					</ul>
				</div>
				
			</nav>
		</div>
	</div>
</div>
<div class="container">
	<div class="row clearfix" >
		<div class="col-md-4 column"> 
<?php
    if($_SESSION['exito'] != "ok"){
?>
			<form role="form" method="post" action="procesaform.php">
				<div class="form-group">
					 <label for="email">Email</label><input type="email" class="form-control" id="email" name="email" required="required" />
				</div>
				<div class="form-group">
					 <label for="password">Password</label><input type="password" class="form-control" id="password" name="password" required="required"/>
				</div>
			    <div class="form-group">
				     <label for="nombre">Nombre</label><input type="text" class="form-control" id="nombre" name="nombre" required="required" />
			    </div>
			    <div class="form-group">
				     <label for="apellidos">Apellidos</label><input type="text" class="form-control" id="apellidos" name="apellidos" required="required" />
			    </div>
                <div class="form-group">
				     <label for="telf">Teléfono</label><input type="text" class="form-control" id="telf" name="telf" required="required" />
			    </div>
                <div class="form-group">
				     <label for="nacimiento">Fecha nacimiento</label><input type="date" class="form-control" id="nacimiento" name="nacimiento" required="required" />
			    </div>
				<div class="form-group">
					 <label for="file">Foto de perfil</label><input type="file" id="file" />
					<p class="help-block">
						No es necesario subir una foto.
					</p>
				</div>
                <div class="form-group">
					     <label for="conociste">¿Cómo conociste la tienda?</label>
                        <select id="conociste" class="form-control">
						<option>Google</option>
    					<option>Amigo</option>
    					<option>Facebook</option>
      					</select>
				    </div>
                <div class="form-group">
					 <label><input type="checkbox" value="1" name="condiciones" required="required" /> Acepto los <a href="#" data-toggle="modal" data-target="#terms">términos y condiciones de uso</a></label>
				</div> <button type="submit" class="btn btn-default" name="boton">Suscribirse</button>
			</form>
<?php
    } else {
?>
    <h2><p>Datos guardados con éxito</p></h2>
<?php
    }
    $_SESSION['exito'] = "";
?>

		</div>
	</div>
</div>

<!-- FOOTER -->
  <hr>
    <footer>
        <div class="row">
            <div class="col-lg-12">
                <ul class="nav nav-pills nav-justified">
                    <li><a href="http://www.ugr.es">© 2015 Universidad de Granada.</a></li>
                    <li><a href="#" data-toggle="modal" data-target="#patrocinadores">Patrocinadores</a></li>
                    <li><a href="#" data-toggle="modal" data-target="#terms">Términos legales</a></li>
                </ul>
            </div>
        </div>
    <div class="modal fade" id="patrocinadores" tabindex="-1" role="dialog" aria-labelledby="basicModal" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">X</button>
                <h4 class="modal-title" id="myModalLabel">Patrocinadores</h4>
                </div>
                <div class="modal-body">
                    <h3>UGR,ETSIIT</h3>
                </div>
        </div>
      </div>
    </div>
    <div class="modal fade" id="terms" tabindex="-1" role="dialog" aria-labelledby="basicModal" aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-hidden="true">X</button>
                <h4 class="modal-title" id="myModalLabel">Términos legales</h4>
                </div>
                <div class="modal-body">
                    <h3>Esta web es una práctica de Tecnologías Web</h3>
                </div>
        </div>
      </div>
    </div>

    </footer>

</body>
</html>
