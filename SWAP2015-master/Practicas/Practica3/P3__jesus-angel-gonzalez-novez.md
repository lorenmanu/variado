# Práctica 3
*Jesús Ángel González Novez*
## Objetivos
* Instalar nginx server
* Usar nginx como balanceador de carga
* Instalar haproxy
* Usar haproxy como balanceador de carga

## Solución
Para instalar nginx usamos el comando "# apt-get install nginx". Para su configuración, a diferencia del guión, he editado el virtual host "default" propio de nginx, en la carpeta sites-enabled, este virtual host es el que lee por defecto nginx si no hay más, casi aseguraría que internamente se hace lo mismo que haciéndolo como en el guión.

Tenemos entonces las siguientes máquinas con los siguientes servidores web:
* Máquina 1 -> Apache(192.168.1.100)
* Máquina 2 -> Apache(192.168.1.101)
* Máquina balanceador -> Nginx(192.168.1.102) 

He editado el fichero html que nos sirven las máquinas 1 y 2 quedando un fichero simple que pone "swap1!" o "swap2!" respectivamente, para diferenciar a simple vista a que máquina nos dirige en cada momento el balanceador.

Tanto de máquina 1 como de máquina 2 vamos a realizar varias veces peticiones al balanceador con el siguiente comando "curl 192.168.1.102" dejando la configuración del balanceador tal cual. En la captura "curl_simple.png" podemos ver como se ha repartido la carga equitativamente mandando cada vez a una de las dos máquinas.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica3/curl_simple.png)

Ahora voy a hacer uso del parámetro "weight" para dar más peso a la máquina 2, para ello editamos de nuevo el fichero de configuración "default" y en la sección upstream a continuación de cada ip añadimos weight=1 para máquina 1 y weight=2 para máquina 2, de esta forma la máquina 2 atenderá más peticiones. Esto es útil si por ejemplo la máquina 1 es menos potente. Una vez hecho esto y tras reiniciar el servicio de nginx, repetimos la operación anterior haciendo varios "curl" a la máquina balanceador. En la captura "curl_con_peso.png" podemos ver que en la máquina 1 de cinco peticiones 4 fueron atendidas por la máquina 2, y en la máquina 2 vemos que de 5 peticiones, 3 fueron atendidas en la máquina 2, esto hace un total de 7/10 peticiones atendidas por la máquina 2.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica3/curl_con_peso.png)

Existen otros parámetros interesantes como pueden ser:
* ip_hash esto sirve para mantener al cliente todo el rato con el mismo servidor final.
* keepalive para mantener persistencia con las conexiones
* max_fails para el número de intentos fallidos
* max_time similar pero para el tiempo de intento 
* down se usa para poner offline el servidor, por ejemplo para tareas de mantenimiento
* backup solo se usará este servidor en caso de caída de los otros (no compatible con ip_hash como era de esperar)

Ahora pasemos a realizar algo similar pero esta vez usando haproxy como balanceador, lo primero de todo es desinstalar nginx y a continuación instalar haproxy. Para ello ejecutamos "# apt-get remove nginx" y "# apt-get install haproxy". Esto es para evitar conflictos, como pasaba con Apache. Y respecto a lo de instalar "joe" he pasado porque he visto que es un editor, y personalmente uso nano.

Vamos lo primero a editar el fichero "/etc/haproxy/haproxy.cfg", los tiempos de srvtimeout,clitimeout y contimeout se los he mantenido, no son diferencias significativas respecto al guión y estimo que son parámetros más subjetivos. Lo importante es añadir los apartados "frontend http-in" donde indicamos que nos tome el puerto 80 y donde dice que carge el "backend servers" que eso donde indicamos las máquinas 1 y 2 de nuestro ejemplo. Estando situados en el directorio "/etc/haproxy" y siendo el usuario root, ejecutamos "haproxy -f haproxy.cfg", de esta manera hemos lanzado el servicio usando esa configuración.

Para probarlo realizamos la misma prueba que anteriormente, haciendo varios curl desde máquina 1 y máquina 2 hacia la balanceadora. En la captura "curl_simple_haproxy.png" podemos ver que efectivamente reparte la carga. Vemos que desde la máquina 1 nos sirvió 3 veces máquina 1 y 2 veces máquina 2 y que desde la máquina 2 nos sirvió 2 veces máquina 1 y 3 veces máquina 2. Esto hace un total de 5 y 5 repartido equitativamente.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica3/curl_simple_haproxy.png)

Haproxy, al igual que nginx, es altamente configurable, podemos también establecer prioridad para las máquinas y otros cuantos de parámetros, visto que el funcionamiento básico ha sido satisfactorio, omitiré realizar las mismas pruebas con haproxy, personalmente uso nginx, de ahí que he hecho más hincapié en la sección de nginx.




