# Práctica 5
*Jesús Ángel González Novez*
## Objetivos
* Copia de seguridad manual de la BD MySQL
* Copia automatizada(maestro-esclavo) de la BD MySQL

## Solución
Primero he creado en máquina 1 una base de datos llamada "almacen" y después he creado una tabla "productos" con algunas tuplas. Ver captura "tabla_productos.png"

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica5/tabla_productos.png)

El siguiente paso es bloquear la BD porque suponemos que está en constante uso, por tanto haremos un "lock".

    FlUSH TABLES WITH READ LOCK;

Ahora ya si haremos el "dump" de la siguiente manera:

    mysqldump almacen -u root -p > /root/almacen_copia.sql

Una vez hecha la copia procedemos a desbloquear de nuevo la BD:

    mysql -u root -p
    UNLOCK TABLES;

Esta vez ya en la máquina 2 realizamos copia por ssh con el comando:

    scp root@192.168.1.100:/root/almacen_copia.sql /root/

Y la importamos(requiere que se cree previamente la BD):

    mysql -u root -p almacen < /root/almacen_copia.sql

Esto está bien pero ahora vamos a ver como se hace realmente con una arquitectura maestro-esclavo que es como se suele trabajar en la realidad.

Editamos los ficheros /etc/mysql/my.cnf como indica el guión. Ver captura "my_cnf.png"

Configuramos el maestro y el esclavo, ver captura "maestro_esclavo.png"

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica5/maestro_esclavo.png)

Finalmente para comprobarlo voy a insertar la tupla ("pan",20,35) en el maestro y verla desde el esclavo. Ver captura "comprobar.png". Como vemos efectivamente se sincroniza automáticamente sin problemas.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica5/comprobar.png)
