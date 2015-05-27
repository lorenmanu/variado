# Fundamentos de JavaScript
* El código JavaScript debe ir en un elemento script de HTML:

        <script type="text/javascript">
            alert("Hola, Mundo");
        </script>
También   el   código   JavaScript   puede   ir   en   un   fichero   externo.   Para   ejecutarlo   se   emplea   el
atributo src de script:
        
        <script  type="text/javascript" src="miGuion.js"></script>
* Los comentarios se hacen mediante /* ... */ ó //.
* Operadores aritméticos:  +,­,*, / y %. Precedencia igual que en otros lenguajes. Se emplean los paréntesis para establecer un orden de evaluación requerido.
* Cadenas   de   caracteres   entre   comillas   dobles   o   simples

        ("Hola.   Esto   es   una   cadena   de  caracteres.").
* El operador de concatenación de cadenas de caracteres es + 

        ("hola" + "adios").
* El carácter '\' se emplea como indicador de caracteres con significado.
* '\n' y '\t' para introducir una nueva línea y un tabulador, respectivamente.
* El operador typeof devuelve una cadena con el tipo de dato del operando (typeof 4.5 devolvería number. Se puede utilizar también como una función var resultado=typeof("hola");).
* Los valores numéricos se pueden comparar mediante los operadores relacionales '>=', '<=', '<', '>', '!=' y '=='. Estos operadores son de aplicación a las cadenas de caracteres y devuelven los valores true o false.
* Los operadores lógicos son: '&&', '||' y '!', y devuelven los valores true o false.
* false será equivalente a  una cadena vacía (" "), 0 ó NaN, null y undefined.
* Todas las sentencias de JavaScript finalizan con un ';'.
* Para   declarar   variables   se   emplea   la   palabra   reservada   var   (var   altura=5.5;).   No   se   puede emplear ninguna variable que no haya sido declara previamente, aunque sea en el momento de asignarle un valor.
* Se puede declarar una variable pero no asignarle ningún valor inicialmente. En este caso, el tipo de   la   misma   es  undefined:
  
        var   mensaje;   resultado=typeof(mensaje);   //   resultado   toma    undefined.
* Cuando se empieza a ejecutar un programa JavaScript, se crea un entorno de variables, junto con sus valores correspondientes. Este entorno está inicializado con un conjunto de variables estándares que el navegador cargará y asignará valores.  Las variables del entorno existirán hasta que el navegador cargue otra página.
* Las funciones en JavaScript se invocan igual que en otros lenguajes. Pueden o no devolver un valor.
* Ventanas de mensajes o diálogos incluidos en el entorno estándar:

        alert("Texto");  →  muestra una ventana con el texto en su interior. También puede mostrar números.
        alert(confirm("Iremos?")); →  Muestra el texto así como dos botones (OK/Cancel) y devuelve true o false según se haya hecho click en OK o en Cancel, respectivamente.
        alert(prompt("Dime   tu   película   favorita:","..."));  →   Muestra   el   texto   pasado   como   primer argumento y un campo de texto para meter un texto de entrada. El segundo argumento es el texto que aparecerá por defecto en el campo de texto.
* Para escribir texto en la propia página web podemos usar la fución document.write('texto'), o si simplemente queremos tener un control sobre las salidas de ciertas funciones podemos usar la consola   de   javascript   mediante   la   función  console.log('texto').   Para   poder   ver   dichos   valores tendremos   que   acceder   a   dicha   consola   (en   el   navegador   Chrome:   menú­>herramientas>Consola de JavaScript). 
* Las estructuras repetitivas de JavaScript son los bucles while y for:

        var contador = 0;
        while (contador <= 12)
            contador = contador + 2;
        for (var contador = 0; contador <= 12; contador = contador + 2)
            document.write(contador);
* Para los cuerpos de bucles de más de una línea, se emplean las llaves para delimitar su ámbito.
Se emplea la sentencia break para romper la ejecución de bucle, continuando después de ella.
* Existen los operadores ++, ­ ­, +=,...
* Se emplean las palabras  break  y  continue  con el mismo significado que en otros lenguajes de programación.
* Las estructuras condicionales de JavaScript son los if y switch:

        for (var cont = 0; cont < 20; cont++) {
            if (cont > 15)
                document.write(cont + "**");
            else if (cont > 10)
                document.write(cont + "*");
            else  document.write(cont);
         }
        var dia=new Date().getDay();
        switch (dia)
        {
            case 0: x="Domingo";
            break;
            case 1: x="Lunes";
            break;
            case 2: x="Martes";
            break;
            case 3: x="Miércoles";
            break;
            case 4:x="Jueves";
            break;
            case 5:x="Viernes"; 
            break;
            case 6:x="Sábado";
            break;
        }

## Funciones
* Las funciones se declaran mediante la palabra reservada function.
* Pueden devolver o  no  valores.  En caso de hacerlo,  se emplea la palabra  return,  y  si  no, realmente devuelven un valor "undefined".

        function add(a, b) {
            return a + b;
        }
        document.write(add(2, 2));
        function mostrarMensaje(mensaje) {
            alert("¡¡"+ mensaje + "!!");
        }
        mostrarMensaje("OOOOleeeeee");
* Los nombres de funciones pueden asignarse a variables y luego emplearlas:

        function mostrarMensaje(mensaje) {
            var funcion=alert;
            funcion("¡¡"+ mensaje + "!!");
        }
        mostrarMensaje("OOOOleeeeee");
* Las variables declaradas dentro de una función son locales a la función, pero las que se declaran fueran pueden ser empleadas dentro de las funciones.
* Se pueden declarar funciones dentro de otras, en cuyo caso, el entorno local de las primeras contendrá el de las segundas:

        var variable = "fuera";
        function funcionPadre() {
            var variable = "local";
            function funcionHija() {
                document.write(variable);
            }
            funcionHija();
        }
        funcionPadre();
* OJO: sólo se crean entornos locales a partir del cuerpo de las funciones. Se pueden crear bloques de código en cualquier momento pero no se crean entornos de variables.
* Se pueden devolver funciones internas y luego invocarlas:

        var variable = "fuera";
        function funcionPadre() {
            var variable = "local";
            function funcionHija() {
                document.write(variable);
            }
            return funcionHija;
        }
        var hija = funcionPadre();
        hija();
        function funcionPara Sumar(cantidad) {
            function sumar(numero) {
                return numero + cantidad;
            }
            return sumar;
        }
        var aniadirDos = funcionParaSumar(2);
        var aniadirCinco = funcionParaSumar(5);
        document.write(aniadirDos(1) + aniadirCinco(1));
* No sólo se devuelve el nombre de la función, sino que también implícitamente se devuelve el  entorno asociado.
* Se permite recursividad.
* Existe el array arguments que almacena todos los argumentos pasados a una función. Sólo se puede emplear dentro de ella (el primer argumento está en la posición 0). Con arguments.length podremos saber cuántos se han pasado a la función.
* No se pueden sobrecargar funciones.
* Se pueden crear valores función al estilo a como se crean e inicializan variables:

        var suma = function(a, b) {
            return a + b;
        };  /* OJO con este ; pues es como si hiciéramos suma=3; */
        document.write(suma(5, 5));
        function funcionParaSumar(cantidad) {
            return function (numero) {
                return cantidad + numero;
            };
        }
        var suma= funcionParaSumar(5);
        document.write(suma(3));

## Objetos
* En JavaScript todo son objetos (Object, de forma genérica; una cadena de caracteres, String; un número, Number; un vector, Array; una función, Function).
* Los objetos son tipos de datos especiales que tienen propiedades y métodos.
* En JavaScript no existe el concepto de clase. No se crean clases explícitamente.
* Las propiedades se acceden mediante un punto, cadena.length, o alternativamente medinte la sintaxis de arrays, cadena["lenght"];
* Los métodos, con la sintáxis clásica: cadena.toUpperCase();
* La creación de objetos se puede hacer de dos formas diferentes:

        libro= new Object();
        libro.autor="Cervantes";
        libro.titulo="Don Quijote de la Mancha";
        libro.anio=1615;
        libro.isbn="343.4335.234";
        /* ó */
        libro={autor:"Cervantes", titulo:"Don Quijote de la Mancha", anio:1615, isbn:"343.4335.234"};
* Los constructores son funciones que se denominan igual que el objeto:

        function libro(autor,titulo,anio,isbn)
        {
            this.autor=autor;
            this.titulo=titulo;
            this.anio=anio;
            this.isbn=isbn;
        }
        var quijote= new libro("Cervantes", "Don Quijote de la Mañcha", 1615, " 343.4335.234");
* Se pueden añadir propiedades en cualquier momento. Simplemente asignándole un valor:

        quijote.editorial="Salvat";
* Se puede emplear this para acceder a un dato miembro de un objeto.
* Los métodos se asignan a un objeto añadiéndolos dentro del constructor correspondiente:

        function libro(autor,titulo,anio,isbn)
        {
            this.autor=autor;
            this.titulo=titulo;
            this.anio=anio;
            this.isbn=isbn;
            function cambiarTitulo(titulo){ 
                this.titulo=titulo; 
            }
        }
* Se pueden crear propiedades que no tengan un nombre como tal, sino, por ejemplo, un objeto cadena de caracteres:

        var mensaje={"De": "Juanma", "Para": "Jose", "Asunto":"Asignatura", "Cuerpo":"Hola, Jose...."};
* Para acceder a los valores que almacena, el objeto se indexa como un vector por dicha propiedad:
        
        mensaje["De"]="Pepe";
* Existe un operador para comprobar si una propiedad existe en un objeto. Este es in, el cual devuelve true si está y false en caso contrario:

        var resultado= "De" in mensaje;
        document.write(resultado);
* Para borrar una propiedad se emplea delete:  delete mensaje["De"];
* Para obtener los valores de los atributos miembro de un objeto se emplea el siguiente bucle:

        var profesor={nombre:"Juanma",apellidos:"Fernández"}; 
        for (x in profesor)
        { datos_profesor=datos_profesor + profesor[x]; }
* Cuando disponemos de una referencia a un objeto, se puede indicar que no apunte a ningún objeto asignándole null.
* Para conocer si un objeto es instancia de un constructor se emplea: 

        var res= quijote instanceof libro; 
Otro ejemplo: 

        var res2= mivector instanceof Array;
* Los datos miembro pueden ser configurable, si puede borrarse mediante delete; enumerable, si  puede ser devuelta por un bucle for­in; writable, si puede ser cambiada, y value, que contiene el valor real de la propiedad. Por defecto, al añadir una propiedad a un objeto, ésta es configurable,enumerable y writable. Para cambiar y asignar una de estas propiedades, se emplea el método defineProperty:
        var persona = {}; 
        Object.defineProperty(persona, "nombre", { 
            writable: false, 
            configurable: false,
            value: "Juanma" 
        }); 
* Una   vez   que   una   propiedad   se   ha   asignado   como   no   configurable,   no   se   puede   cambiar.Cualquier intento, da lugar a una excepción.
* Existen también "Accessor properties" (configurable, enumerable, get y set). Las dos últimas son funciones para obtener y devolver el valor de una propiedad.

        var libro = { 
            _anio: 2004, 
            edicion: 1 
        }; 
        Object.defineProperty(libro, "anio", { 
            get: function(){ 
                return this._anio; 
            }, 
            set: function(valor){ 
                if (valor > 2004) { 
                    this._anio = valor; 
                    this.edicion += valor ­ 2004; 
                } 
            } 
        }); 
        libro.anio = 2005; // OJO, no le estamos asignado directamente un valor a _anio.
        alert(libro.edicion); //2 
* Cuando se precede el nombre de una propiedad mediante "_" se está dando a entender que no será accedida directamente, sino implícitamente mediante get y set.
* Para definir varias propiedades a la vez:

        var libro = {}; 
        Object.defineProperties(libro, { 
            _anio: { 
                value: 2004 
            }, 
            edicion: { 
                value: 1 
            },
            anio: { 
                get: function(){ 
                    return this._anio; 
                }, 
                set: function(valor){ 
                    if (valor > 2004) { 
                        this._anio = valor; 
                        this.edicion += valor ­ 2004; 
                    } 
                } 
            } 
        }); 
* Otros conceptos de la orientación a objetos de JavaScript: el patrón Prototype y herencia.
JavaScript es un lenguaje basado en prototipos, lo que significa que los objetos heredan directamente de otros objetos (no existen clases). Cuando un objeto se crea, se crea a su vez una propiedad llamada prototype.
* Uso de prototype para herencia:

La propiedad prototype de un objeto puede cambiarse, quedando cambiada también cada instancia de dicho objeto aunque las instancias sean anteriores al cambio hecho mediante prototype. Lo mismo ocurre si cambiamos métodos de un objeto usando prototype.

        function Animal (tipo, color){
            this.tipo = tipo;
            this.color = color;
        }
        var conejo = new Animal(“mamífero”, “blanco”);
        var pantera = new Animal(“felino”, “negro”);
        //para para definir nuevas propiedades y métodos 
        Animal.prototype.peso = 8;
        Animal.prototype.mostrarPeso = function(){ 
            console.log(this.peso); 
        } 
        //o para cambiarpropiedades y métodos ya creados de un objeto
        Animal.prototype.mostrarPeso = function(){
            aumento= 2;
            this.peso += aumento;
            console.log(this.peso);
        }

## Arrays
Véase [http://www.w3schools.com/js/js_obj_array.asp](http://www.w3schools.com/js/js_obj_array.asp)
* Los arrays se inicializan mediante corchetes: 

        var animales= ["perro", "gato", "león"].
* Se asignan valores mediante un índice: animales[4]="tigre". El acceso es el típico: 

        animales[1];
* El primer índice del vector es 0.
* Se pueden crear arrays vacíos: 

        var animales[];
* Realmente un vector es un objeto de la clase  Array, por lo que se pueden aplicar métodos a dichos objetos:
* Construcción: 

        var coches= new Array(); 
            ó 
        var coches= new Array("Seat", "Audi", "Volvo");
* Para incluir nuevos elementos se emplea el método push: 

        animales.push("elefante");  
Se añade al final de array. 
* El   número   de   elementos   del   array   se   obtiene   mediante   la   propiedad  length

        animales.length
* El índice de un valor se obtiene por medio de indexOf: 

        var pos= coches.indexOf("Audi");
* Para concatenar Arrays se emplea el método concat.
* Para obtener el último elemento se usa el método pop.
* Otros métodos: join, reverse, shift, slice, sort, splice, toString, unshift,...
* Se pueden almacenar diferentes tipos de datos en un array, ya que todos los componentes de un Array se consideran objetos.
* Se pueden añadir elementos al vector en cualquier posición, aunque no esté lleno hasta ella.

## Cadenas de caracteres
Véase[http://www.w3schools.com/jsref/jsref_obj_string.asp](http://www.w3schools.com/jsref/jsref_obj_string.asp)
* Son objetos.
* Creación: 

        var nombre="Juan Manuel"; 
            ó 
        var nombre='Juan'; 
        No hay diferencia entre "X" y 'X'.
* Se puede acceder a una posición concreta (los índices comienzan en 0): 

        var car=nombre[3];
* Se emplea el carácter '\' para escapar otros caracteres.
* Longitud de la cadena: nombre.length;
* Encontrar la posición donde comienza una subcadena: 

        var pos=nombre.indexOf("Manuel"); 
        Devuelve ­1 si no está la subcadena.
* Sustitución de subcadenas: 

        var cad="Juan Manuel"; 
        pos= cad.replace("Juan", "José");
* Conversión a mayúsculas y minúsculas: 

        cad2=cad.toUpperCase(); 
        cad3=cad.toLowerCase();
* Conversión de una cadena a un vector: 

        var str="a,b,c,d,e,f"; 
        var n=str.split(",");
* Más métodos en [http://www.w3schools.com/js/js_obj_string.asp](http://www.w3schools.com/js/js_obj_string.asp).

## Otros objetos
* Date [http://www.w3schools.com/js/js_obj_date.asp](http://www.w3schools.com/js/js_obj_date.asp).
* Math [http://www.w3schools.com/js/js_obj_math.asp](http://www.w3schools.com/js/js_obj_math.asp).
* RegExp [http://www.w3schools.com/js/js_obj_regexp.asp](http://www.w3schools.com/js/js_obj_regexp.asp).

## El Document Object Model
El   Document  Object   Model   (DOM)  es  un   API   para   documentos  HTML y XML, que permite representar el árbol del documentos y añadir,  borrar y modificar partes individuales del mismo. 

La referencia de este módulo se puede encontrar en [http://www.w3schools.com/js/js_htmldom.asp](http://www.w3schools.com/js/js_htmldom.asp). 

Ejemplos de su uso en [http://www.librosweb.es/javascript/capitulo_5.html](http://www.librosweb.es/javascript/capitulo_5.html).

## El Browser Object Model
El   Browser   Object   Model   (BOM)   es  un  API   que  permite  la   manipulación   de   la   ventana   del navegador, de tal forma, que los desarrolladores pueden interactuar con el navegador fuera de la página
que está siendo mostrada actualmente. No es un estándar y los navegadores lo implementan de forma diferente,   aunque   sí   hay   un   núcleo   común.

Información   sobre   este   API   podéis   encontrarla   en [http://www.w3schools.com/js/js_window.asp](http://www.w3schools.com/js/js_window.asp) y [http://librosweb.es/ajax/capitulo_5.html](http://librosweb.es/ajax/capitulo_5.html).

## Eventos DOM
La programación  basada en  en eventos consiste, grosso modo,  en asociar    código a   posibles situaciones que pueden ocurrir en una aplicación (hacer click en un botón o en un enlace, pasar el ratón por algún lugar). Hasta ese momento no se ejecuta ningún programa, en oposición con la programación tradicional   donde   hay   un   programa   principal   que   se   lanza   explícitamente.   JavaScript   ofrece   la posiblidad de programar de forma basada en eventos.   Podéis encontrar más información sobre eventos en  [http://www.w3schools.com/js/js_htmldom_events.asp](http://www.w3schools.com/js/js_htmldom_events.asp) y [http://librosweb.es/javascript/capitulo_6.html](http://librosweb.es/javascript/capitulo_6.html).
