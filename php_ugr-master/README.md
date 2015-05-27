# Nociones de PHP
## Iniciación al lenguaje de programación php
* Las sentencias en PHP deben ir incluidas entre <?php <!­­ Codigo PHP ­­>  ?> y se incluyen en código HTML.
* Todas las sentencias deben acabar en punto y coma ;
* La sentencia echo muestra cadenas, numeros, separados por comas.

        <p>Esto es una línea de HTML.</p>
        <?php
            echo "<p>Y esto una línea de PHP.</p>";
            phpinfo();
            /* Esto son unos ejemplos de la sentencia echo. */
            echo "Hola, caracola", 134;
            echo "Adiós ", "Bye";
            echo '<p>Nueva \n linea</p>';
            # Comentario de una línea.
            echo "<p>Nueva <br/>\n linea </p>";
        ?>

        <?php
            /* Esto son unos ejemplos de la sentencia echo. */
            echo "Hola, caracola", 134;
            echo "Adiós ", "Bye";
            echo '<p>Nueva \n linea</p>';
            # Comentario de una línea.
            echo "<p>Nueva <br/>\n linea </p>";
        ?>

Ver fichero [hello.php](https://github.com/jesusgn90/php_ugr/blob/master/php/hello.php)

## Variables y expresiones
* Las variables comienzan con el signo del dolar $
* Pueden tener cualquier longitud
* Sólo incluyen letras,números y guiones bajos(_)
* Puede empezar por una letra o por un guión bajo.
* PHP es un lenguaje sensible a mayúsculas, por lo que $ciudad != $Ciudad

        <?php
            $edad=21;
            $precio=343.45;
            $nombre= "Pepe";
            $nombre2 = $nombre;
            print_r($nombre);
            echo $nombre2;
        ?>

Ver fichero [variables.php](https://github.com/jesusgn90/php_ugr/blob/master/php/variables.php)

* No se declaran previamente a su uso
* Este lenguaje también considera falsos la cadena "false" ó "FALSE", el entero 0, el real 0.0, una cadena vacía, una cadena con el carácter "0" y la constante NULL.

## Operaciones básicas
* Para hacer un casting -> $nuevoEntero=(int) $var1;
*   Las operaciones básicas que pone PHP a disposición del programador son +, ­, *, / y % (resto).
* También   existen   los   operadores   de   incremento   (++)   y   decremento   (–   (dos   guiones))   de   una unidad ($var= $var +1; ó $var+=1). Para añadir, restar, multiplicar o dividir por un valor, se emplea la
sentencia $var *=3;  (para el caso del producto).
* La   función number_format(numero,   numero_de_decimales,   "separador_decimales", "separador_miles") permite informar a PHP de la forma en que desea mostrar los números.

        <?php
            $numero=12321.666;
            /* Formatea el número con dos decimales y '.' y ',' como separadores decimales y miles */
            echo number_format($numero,2),”<br/>”;
            /* Formatea el número con 2 decimales y con el ',' y de decimales  y la '.' de miles */
            echo number_format($numero,2,",","."); 
        ?>

Ver fichero [number_format.php](https://github.com/jesusgn90/php_ugr/blob/master/php/number_format.php)

* Existe también la posibilidad de que el valor que se guarde en una variable sea el nombre de una variable.

        <?php
            $nombre_de_la_variable="temperatura"
            $$nombre_de_la_variable= 30.5;
            /* Esto implicaría que $temperatura=30.5; */
        ?>

Ver fichero [nombre_variable.php](https://github.com/jesusgn90/php_ugr/blob/master/php/nombre_variable.php) 

* Para eliminar el contenido de una variable se emplea la siguiente sentencia: $variable=_;
* Para destruir una variable se usa la función unset: unset($variable).
* Las constantes se crean mediante: define("nombre_de_la_constante", valor).

        <?php
            define("PI",3.1415);
            define("TIEMPO", "soleado");
        ?>

Ver fichero [define_constante.php](https://github.com/jesusgn90/php_ugr/blob/master/php/define_constante.php) 

* PHP pone a disposición del programador una gran cantidad de constantes predefinida.
 
Véase [language.constants.predefined.php](http://www.php.net/manual/es/language.constants.predefined.php)

## Cadenas de caracteres
* Las cadenas van entre comillas dobles o simples.
* Los caracteres se escapan mediante '\': $cad1="Where is Juan\'s son?";
* La concatenación de caracteres se hace mediante el operador '.': 

Ver fichero [cadenas1.php](https://github.com/jesusgn90/php_ugr/blob/master/php/cadenas1.php) 

Ver fichero [cadenas2.php](https://github.com/jesusgn90/php_ugr/blob/master/php/cadenas2.php) 

### Funciones útiles para cadenas
        trim($cad) /* Elimina espacios en blanco al principio y al final.*/
        ltrim($cad) /* Elimina espacios al principio.*/
        rtrim($cad) /* Elimina espacios al final.*/
        str_word_count($cad, formato) /* Divide una cadena en palabras y las guarda en un array */

Ver fichero [cadenas3.php](https://github.com/jesusgn90/php_ugr/blob/master/php/cadenas3.php) 

Véase [ref.strings.php](http://www.php.net/manual/es/ref.strings.php)

## Gestión de errores
* Para modificar la conducta de PHP frente a errores, se puede cambiar el valor asignado a la variable error_reporting 

Ver fichero [errores.php](https://github.com/jesusgn90/php_ugr/blob/master/php/errores.php) 

* Mediante la función trigger_error, se puede interrumpir la ejecución de un guión tras haberse detectado un error por el cuál no puede seguir ejecutándose.

Ver fichero [errores2.php](https://github.com/jesusgn90/php_ugr/blob/master/php/errores2.php) 

* También se pueden gestionar de forma  personal los errores, para  lo cual se puede avisar  al usuario mediante un echo y seguidamente hacer uso de la función exit(); para terminar la ejecución del guión. 

* También podemos escribir el log de errores.

Ver fichero [errores3.php](https://github.com/jesusgn90/php_ugr/blob/master/php/errores3.php) 

* Por último, comentar que también se puede escribir un manejador de errores propio e indicarle a PHP que lo emplee cuando se produzca un error: 

        set_error_handler(nombre_funcion);

## Vectores(arrays)
Véase [language.types.array.php](http://www.php.net/manual/es/language.types.array.php)

* Un vector puede verse como una lista de pares clave (índice) / valor, almacenados como sigue:

        $nombre_del_vector['clave1'] = valor1;
        $nombre_del_vector['clave2'] = valor2;
        $nombre_del_vector['clave3'] = valor3;
* La clave puede ser una cadena de caracteres o un número entero: 

        $capitales['Spain']='Madrid';
* También se pueden crear sin indicar el índice, pero en este caso la clave es entera y comienza por cero:

        $capitales[] = "Madrid";
        $capitales[] = "Londres";
* Así, "Madrid" estará situada en la posición 0, mientras que "Londres" lo estará en la 1.Otra forma de crear vectores es enumerando en una misma   sentencia sus elementos(comenzando por el índice 0):

        $capitales = array("Londres","Madrid","Berlín");
* Para indicar el índice por el que se desea comenzar se emplea la siguiente sintaxis:

        $capitales = array(12 >="Londres","Madrid","Berlín");
* Para crear vectores por enumeración pero con cadenas de caracteres como claves:

        $capitales = array ( "SP" => "Spain","UK "=> "Reino Unido" , "USA"=> "Salem" );
* PHP también nos permite crear vectores mediante rangos:

        $anios = range(2001, 2010);
        $letras=range("z", "a");
* Para mostrar vectores se pueden emplear las funciones print_r y var_dump, con el vector a visualizar como argumento.
* Si queremos mostrar el contenido de algún vector mediante alguna de estas dos funciones en un navegador, es conveniente incluir su salida en un elemento pre de HTML y así no aparecerá todo en una única línea en el navegador.

        <?php
            echo "<pre>";
            var_dump($customers);
            echo "</pre>";
        ?>
* Si queremos modificar un valor para una clave, simplemente asignarle el nuevo valor a la clave correspondiente. Si no existe dicha clave, se añade al final.

        $capitales['Andalucia'] = "Granada";
* Igual ocurre si se asigna un valor sin especificar a la clave, aunque en este caso para claves numéricas:

        $capitales[1] = "Madrid";
        $capitales[2] = "Murcia";
        $capitales[] = "Granada"; /* En este caso se asigna al índice 3. */
* Para obtener un valor, simplemente se indexa el vector por la clave correspondiente:

        $ciudad= $capitales[1];
* Para copiar un vector íntegramente en otro, simplemente asignarlos: 

        $unVector= $otroVector;
* Para borrar un elemento, se debe emplear la función unset: 

        unset($capitales[2]);
* Nótese que las claves no cambian al borrar un elemento intermedio.
* El tamaño de un vector se obtiene con las funciones:
        
        count($vector) y sizeof($vector).
* Para ordenar los valores de vectores con números como claves en orden ascendente, se debe emplear la función sort (en sentido descendente, rsort). * En el caso de desear ordenar un vector con cadenas de caracteres, se utiliza la función asort (análogamente arsort).
* Y cuando se quiera ordenar las claves, se utiliza ksort (o krsort para ordenarlo en sentido contrario).
* Se pueden asignar los n primeros valores de un vector a n variables mediante la sentencia list:

        list($primero, $segundo, $tercero)= $capitales; /* Se copian los tres primeros valores */
        echo $primero, " ", $segundo, " ", $tercero;
* Para recorrer un vector de forma manual se emplean punteros a los elementos del vector, por medio de las siguientes funciones:

        $valor= current($vector); → devuelve el valor del elemento actual (al que apunta el vector).
        $valor= next($vector); → devuelve el valor del elemento siguiente al actual y modifica a dicho elemento 
        el puntero.
        $valor= previous($vector); → devuelve el valor del elemento anterior al actual y modifica a dicho 
        elemento el puntero.
        $valor= end($vector); → mueve el puntero al último valor del vector y lo devuelve.
        $valor=reset($vector); → mueve el puntero al primer valor del vector y lo devuelve.
* Las funciones previous, next, end y reset pueden emplearse sin almacenar el valor devuelto. 
* Para obtener la clave del elemento del vector en el que se encuentra el puntero actualmente, se emplea la función:

        key($vector);
* También podemos iterar por un vector mediante la función foreach:

        <?php
            $vectorPoblaciones = array ( "ES" => 34501130, "FR" => 5494423, "CH" => 333472867);
            ksort($vectorPoblaciones);
            foreach($vectorPoblaciones as $nacion => $poblacion )
            {
                $poblacion = number_format($poblacion);
                echo "$nacion: $poblacion.<br/>";
            }
            /* Si se utilizara foreach tal que así:
            foreach($vectorPoblaciones as $poblacion)
             {...}
                se almacenan sólo los valores en la variable $población sucesivamente. */
        ?>

Véase [for_each.php](https://github.com/jesusgn90/php_ugr/blob/master/php/for_each.php)
* Para convertir una cadena de caracteres a un vector, se emplea la función explode:

        <?php
            $cadena = "Esto es una cadena de caracteres";
            $vector = explode(" ",$cadena); /* El primer argumento establece la cadena usada para separar y el segundo la cadena en sí. */
            print_r($vector);
        ?>
* Y al contrario, la función implode:

        <?php
            $vector = array("Esto", "es", "una", "cadena", "de", "caracteres");
            $cadena = implode(";",$vector); /* El primer argumento establece la cadena usada para separar los elementos del vector y el segundo la cadena en sí. */
            echo $cadena;
        ?>
#### Otras operaciones que podemos realizar con vectores son las siguientes:
* Para convertir variables en vectores y viceversa, se emplean las funciones  extract y compact, respectivamente.
* Y para partir y mezclar vectores, las funciones array_split y array_merge, respectivamente.
* Si queremos comparar vectores, debemos emplear la función array_diff($vector1, $vector2), la cual crea un nuevo vector con los elementos que están en el primer vector pasado como argumento y no en el segundo.
* La intersección de vectores se puede hacer con la función array_intersect($vector1, $vector2,...);
* Para sumar los elementos de un vector se emplea array_sum($vector);
* El borrado de valores duplicados se hace mediante $sin_duplicados=array_unique($vector);
* Para intercambiar claves y valores (los valores serán las claves y éstas los nuevos valores) se usa la función $intercambiado= array_flip($vector);

#### Matrices
* Las   matrices (vectores de dos dimensiones o vector de vectores) se pueden crear en PHP de las siguientes formas.
        
        <?php
            $precios['verdura']['patata'] = 1.00;
            $precios['fruta']['manzana'] = 2.50;
            $vehiculos['coche'][] = "Ford";
            $vehiculos['coche'][] = "Seat";
            $precios = array(
            "verdura"=>array("patata"=>1.00,"cebolla"=>.50),
            "fruta"=>array("manzana"=>2.50,"naranja"=>2.00));
            /* Podríamos decir que las claves son "verdura" y "fruta" y sus valores un
             vector cada una.*/
        ?>

Véase [matrices.php](https://github.com/jesusgn90/php_ugr/blob/master/php/matrices.php) 
* El acceso a un valor pasa por la indicación de las claves correspondientes, como hemos visto en el ejemplo. Por extensión, se pueden crear vectores de más de dos dimensiones. En PHP existen varios arrays predefinidos que almacenan datos relacionados con el servidor, sistema operativo, o incluso variables globales. En [http://php.net/manual/en/reserved.variables.php](http://php.net/manual/en/reserved.variables.php) puedes encontrar la lista de dichos vectores, así como su descripción y ejemplos de uso.

## Control de flujo
* Las sentencias condicionales de PHP son dos: if y switch

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

Véase [if_switch.php](https://github.com/jesusgn90/php_ugr/blob/master/php/if_switch.php)

* Existen tres tipos de bucles:for,while y do-while

        <?php
            /* Bucle for */
            for($i=1;$i<=9;$i++)
            {
                echo "\nTabla del multiplicar del $i \n";
                for($j=1;$j<=9;$j++)
                {
                    $result = $i * $j;
                    echo "<p>$i x $j = $result<p>\n";
                }
            }

            /* Bucle while */
            $fruta = array ( "naranja", "manzana", "uvas" );
            $encontrada = "no";
            $k = 0;
            while ( $encontrada != "si" )
            {
                if ($fruta[$k] == "manzana" )
                {
                    $encontrada = "si";
                    echo "manzana\n";
                }
                else
                  echo "$fruta[$k] no es una manzana\n";
                $k++;
            }

            /* Bucle do... while */
            $encontrada = "no";
            $k = 0;
            do
            {
                if ($fruta[$k] == "manzana" )
                {
                    $encontrada = "si";
                    echo "manzana\n";
                }
                else
                  echo "$fruta[$k] no es una manzana\n";
                $k++;
            } while ( $encontrada != "si" )
        ?>

Véase [if_switch.php](https://github.com/jesusgn90/php_ugr/blob/master/php/bucles.php)

* Para incluir código PHP en otros guiones PHP se emplea la sentencia  include.Veamos un ejemplo.Definimos dos constantes en el fichero tamanio.inc (se suele emplear en estos casos la extensión .inc – el intérprete de PHP no procesará nunca estos ficheros aisladamente)

        <?php
            /* Fichero tamanio.inc */
            define("ALTURA",60);
            define("ANCHURA",60);
        ?>
        <?php
            include('tamanio.inc');
        ?>
        <img src="imagen.jpg" height="<?php echo ALTURA?>" width="<?php echo ANCHURA?>" />

## Las funciones en PHP
Véase [language.functions.php](http://www.php.net/manual/es/language.functions.php)

* Se suelen definir en un fichero .inc separado del lugar donde se usan,   aunque también se pueden definir dentro del mismo fichero .php en el que se emplean.

        function aniadir_pie()
        {
            echo ' <footer> <img src="escudo_ugr.jpg" width="100%" height="7" />
            <address>Universidad de Granada
            <br />Cuesta del Hospicio, s/n
            <br />Granada, 18071
            </address>
            <p>Contacto: <a href="mailto:info@ugr.es">UGR </a> </p> </footer>';
        }

* Otro ejemplo pero con argumentos y retorno sería:

        function aniadir_pie2($servicio,$dirCElectronico)
        {
            $cadena= ' <footer> <img src="escudo_ugr.jpg" width="100%" height="7" />
            <address> <p>'. $servicio.' Universidad de Granada</p>
            <br />Cuesta del Hospicio, s/n
            <br />Granada, 18071
            </address>
            <p>Contacto: <a href="mailto:'.$dirCElectronico.'">UGR </a> </p> </footer>';
            return $cadena;
        }

Véase [funcion.php](https://github.com/jesusgn90/php_ugr/blob/master/php/funcion.php)

* Para usar la función basta con:

        aniadir_pie();
        $salida=aniadir_pie2("Servicio de habilitación", "habilitacion@ugr.es");

* Se pueden asignar valores por defecto a los parámetros de entrada de la siguiente forma:

        function suma($num1=1,$num2=1)
        {
            $total = $num1 + $num2;
            return $total;
        }

* La función se puede invocar con cero, uno o dos parámetros de entrada. Si no aparece ninguno, se le asigna 1 por defecto a los parámetros num1 y num2. Si es uno, num1 tomará el valor del parámetro de entrada, mientras que a num2 se le asigna el valor por defecto, 1. Finalmente, si se pasan dos argumentos de entrada, num1 y num2 toma los valores correspondientes:

        $resultado=suma(2,2);
        $resultado=suma(2);
        $resultado=suma();
* También se pueden pasar valores por referencia. Para ello, se pone   delante del parámetro correspondiente un &:

        function incrementar(&$num)
        {
            $num=$num+1;
        }
* A veces la ejecución de una función puede fallar (imagínese una función que accede a una base de datos para recuperar ciertos datos y ésta no está operativa). Se puede dejar que PHP muestre un aviso o generar nuestro  propio mensaje mediante la función die("mensaje") y parar la ejecución del guión. El uso de die se hace conjuntamente con la invocación de la función:

        consultarBD($consulta) or die("Error: no se puede acceder a la base de datos");



