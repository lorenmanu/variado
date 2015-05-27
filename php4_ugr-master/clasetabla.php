<?php 
        require_once ('datosObject.class.inc'); 
        class Fruta extends DataObject { 
            protected $datos = array("id" => "","nombre" => "",           "color" => "", "tipo"=>""); 
            public static function obtenerFrutas( $filaInicio, $numeroFilas, $orden ) { 
                $conexion = parent::conectar(); 
                $sql = "SELECT SQL_CALC_FOUND_ROWS * FROM " . TABLA_FRUTAS . " 
                ORDER BY “ . $orden . “LIMIT :filaInicio, :numeroFilas"; 
                try { 
                    $st = $conexion­>prepare( $sql ); 
                    $st­>bindValue( ":filaInicio", $filaInicio, PDO::PARAM_INT ); 
                    $st­>bindValue( ":numeroFilas", $numeroFilas, PDO::PARAM_INT ); 
                    $st­>execute(); 
                    $frutas = array(); 
                    foreach ( $st­>fetchAll() as $fila ) { 
                        $frutas[] = new Fruta( $fila ); 
                    } 
                    $st = $conexion­>query( "SELECT found_rows() AS filasTotales" ); 
                    $fila = $st­>fetch(); 
                    parent::desconectar( $conexion ); 
                    return array( $frutas, $fila["filasTotales"] ); 
                } catch ( PDOException $e ) { 
                    parent::desconectar( $conexion ); 
                    die( "Consulta fallida: " . $e­>getMessage() ); 
                } 
            } 
            public static function obtenerFruta( $id ) { 
                $conexion = parent::conectar(); 
                $sql = "SELECT * FROM " . TABLA_FRUTAS . " WHERE id = :id"; 
                try { 
                    $st = $conexion­>prepare( $sql ); 
                    $st­>bindValue( ":id", $id, PDO::PARAM_INT ); 
                    $st­>execute(); 
                    $fila = $st­>fetch(); 
                    parent::desconectar( $conexion ); 
                    if ( $fila ) return new Fruta( $fila ); 
                } catch ( PDOException $e ) { 
                    parent::desconectar( $conexion ); 
                    die( "Consulta fallada: " . $e­>getMessage() ); 
                } 
            } 
            public static function insertarFruta(...){ 
                /* Código para insertar una fruta en la tabla. */
            }
            // Aquí también se meterían métodos que procesaran los campos de alguna forma.
            public function obtenerTipoCadena() { 
                return ( $this­>datos["tipo"] == "s" ) ? "Seco" : "Carnoso"; 
            } 
        } 
    ?> 
