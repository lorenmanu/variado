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
			<div class="page-header">
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
						<li class="active">
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
                        <li>
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
            <center><h1>
                <?php 
                    if($_GET['tipo'] == 1)
                        echo 'Portátiles'; 
                    if($_GET['tipo'] == 2)
                        echo 'Sobremesa';
                    if($_GET['tipo'] == 3)
                        echo 'Componentes';
                ?>
            </h1></center>
		</div>
	</div>

<!-- CUERPO PRINCIPAL -->
	<div class="row clearfix">
		<div class="col-md-7 column">
<?php
    mysql_connect('localhost','x76440070','x76440070')or die ('Ha fallado la conexión: '.mysql_error());

    mysql_select_db('db76440070')or die ('Error al seleccionar la Base de Datos: '.mysql_error());
    $modelo = $_GET['modelo'];
    mysql_query("SET NAMES 'utf8'");
    $result = mysql_query("SELECT * FROM producto WHERE modelo = '$modelo'");
    $row = mysql_fetch_array($result);

    mysql_free_result($result);

    mysql_close();
?>
<?php if($row){ ?>

            <h2><?php echo $row['nombre']; ?></h2>
            <div class="carousel slide" id="carousel-283433">
	            <ol class="carousel-indicators">
		            <li class="active" data-slide-to="0" data-target="#carousel-283433">
		            </li>
		            <li data-slide-to="1" data-target="#carousel-283433">
		            </li>
		            <li data-slide-to="2" data-target="#carousel-283433">
		            </li>
	            </ol>
	            <div class="carousel-inner" align="center">
		            <div class="item active">
			            <img alt="" src="portatiles/<?php echo $row['modelo']; ?>/1.png" />
		            </div>
		            <div class="item">
			            <img alt="" src="portatiles/<?php echo $row['modelo']; ?>/2.png" />
		            </div>
		            <div class="item">
			            <img alt="" src="portatiles/<?php echo $row['modelo']; ?>/3.png" />
		            </div>
	            </div> 
                <a class="left carousel-control" href="#carousel-283433" data-slide="prev">
                    <span class="glyphicon glyphicon-chevron-left"></span>
                </a> 
                <a class="right carousel-control" href="#carousel-283433" data-slide="next">
                    <span class="glyphicon glyphicon-chevron-right"></span>
                </a>
            </div>
            <dl>
	            <dt><h2>
		            Descripción
	            </h2></dt>
	            <dd>
		            <?php echo $row['description']; ?>
	            </dd>
	            <dt><h2>
		            Características
	            </h2></dt>
	            <dd>
                    <?php echo $row['caracteristicas']; ?>
	            </dd>
                <dt><h3>
                    Precio
                
                </h3></dt>
                <dd>
                    <?php echo $row['precio']; ?>
                </dd>
            </dl>
            <h3>Opiniones de los clientes</h3>
            <?php
    mysql_connect('localhost','x76440070','x76440070')or die ('Ha fallado la conexión: '.mysql_error());

    mysql_select_db('db76440070')or die ('Error al seleccionar la Base de Datos: '.mysql_error());
    $modelo = $_GET['modelo'];
    mysql_query("SET NAMES 'utf8'");
    $result = mysql_query("SELECT * FROM comentario WHERE modelo = '$modelo'");
    
    while($row = mysql_fetch_array($result,MYSQL_NUM)){
        echo '<blockquote><p>';
        echo $row[1];
        echo '</p><small>Escrito por ';
        echo $row[0];
        echo ', a fecha ';
        echo $row[2];
        echo '</small></blockquote>';
    }

    mysql_free_result($result);

    mysql_close();
?>
<?php
    if(!isset($_SESSION['usuario'])) 
    {
        echo '<p> Para publicar comentarios por favor inice sesión.</p>';
    }else{
?>
        <form role="form" action="comentar.php" method="post">
        <input name="comentario" type="text" />
        <input name="modelo" value="<?php echo $_GET['modelo']; ?>" type="hidden"/>
        <input name="tipo" value="<?php echo $_GET['tipo']; ?>" type="hidden" />
        <input name="comentar" class="btn btn-default" type="submit" value="Comentar" />
        </form>
<?php
    }
?>            
<?php }else{ 
        $url = $_SERVER["REQUEST_URI"];
?>
       <?php
                echo $url;
                echo ' not found!<br>';
            ?>
            <h3>Producto no encontrado en la base de datos</h2>
<?php } ?>
		</div>
		<div class="col-md-5 column">
            <h1> Productos relacionados</h1>
            <img alt="400x200" src="portatiles/portatil_asus_x552lav/1.png"><br>
            <a href="producto.php?modelo=portatil_asus_x552lav&tipo=1">Ver detalles >></a><br><br>
		    <img alt="400x200" src="portatiles/portatil_acer_x2509/1.png"><br>
            <a href="producto.php?modelo=portatil_acer_x2509&tipo=1">Ver detalles >></a><br><br>
            <hr>
            <h1>Anuncios</h1>
            <img alt="400x200" src="http://lorempixel.com/200/400/"><br><br>
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
