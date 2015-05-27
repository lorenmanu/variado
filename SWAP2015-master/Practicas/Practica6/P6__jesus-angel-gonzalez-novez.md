# Práctica 6
*Jesús Ángel González Novez*
## Objetivos
* Configurar dos discos RAID1
* Automontaje de los discos al inicio
* Simular fallos, retirar discos, ...

## Solución
Utilizaré la máquina 1. En mi caso uso Virtual Box por lo que debemos ir a la configuración de la máquina y añadir los discos. Ver capturas "vb_discouno.png" y "discos.png" para ver el resultado.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/vb_discouno.png)
![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/discos.png)

Una vez hecho esto, arrancamos y buscamos la información relativa a los discos necesaria para realizar el RAID, ver captura "fdisk.png":

    fdisk -l

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/fdisk.png)

Como vemos tenemos "/dev/sdb" y "/dev/sdc" como los dos nuevos discos. Creamos el RAID1, le damos formato y montamos la unidad en el directorio previamente creado "/datos"
    
    mdadm -C /dev/md0 --level=raid1 --raid-devices=2 /dev/sdb /dev/sdc
    mkfs /dev/md0
    mkdir /datos
    mount /dev/md0 /datos

Para asegurarnos de que se creó correctamente ejecutamos, ver captura "estadoraid.png":

    mdadm --detail /dev/md0

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/estadoraid.png)

Ahora vamos a simular un fallo de disco a propósito, ver captura "fallodisco.png":

    mdadm --manage --set-faulty /dev/md0 /dev/sdb
    mdadm --detail /dev/md0

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/fallodisco.png)

Como vemos, uno de los discos ha caído, pero el otro no. Ahora vamos a eliminar el disco en caliente, esto lo hacemos así, ver captura "discocaliente.png":

    mdadm /dev/md0 -r /dev/sdb
    mdadm --detail /dev/md0

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/discocaliente.png)

Finalmente vamos a añadirlo de nuevo y comprobar que todo esta bien, ver captura "final.png":

    mdadm /dev/md0 -a /dev/sdb1
    mdadm --detail /dev/md0
    
Si nos fijamos esta "rebuilding", es decir sincronizando de nuevo el disco. Con esto queda visto el uso básico de discos RAID1.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica6/final.png)


    

    


