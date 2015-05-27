# Práctica 2
*Jesús Ángel González Novez*
## Objetivos
* Conectar por ssh las máquinas 1 y 2 usando las claves públicas para
no usar contraseña. 
* Probar rsync para sincronizar /var/www desde máquina 2
* Programar tarea cron para sincronizar con rsync desde máquina 2

## Solución
Lo primero ha sido modificar el fichero /etc/ssh/sshd_config y cambiar
la linea "PermitRootLogin without-password" por "PermitRootLogin yes"
para poder acceder sin problemas por ssh como root.

A continuación en la máquina 2 he creado la clave publica para root con:
"ssh-keygen -t dsa", despues la he pasado a la máquina 1 con "ssh-copy-id -i 
.ssh/id_dsa.pub root@192.168.1.100" esta ip es la que he asignado a la 
máquina 1 yo de forma manual.

![img](https://github.com/jesusgn90/SWAP2015/blob/master/Practicas/Practica2/ssh_M1_a_M2_sin_password.png)

También he hecho el proceso inverso para la máquina 1 hacia la máquina 2.
Haciendo una primera prueba he creado un fichero tonto en la máquina 1, 
"echo "hola" > /var/www/prueba.html", este fichero lo he sincronizado desde
la máquina 2 con "rsync -avz -e ssh root@192.168.1.100:/var/www/ /var/www"
y efectivamente se realiza la copia, ignorando ficheros similares que ya 
existiesen(la carpeta /var/www/html existia en ambas máquinas) y cogiendo 
solamente el fichero "prueba.html"

A continuación he configurado "cron" para realizar una sincronización cada
hora del directorio /var/www, para ello he creado un script llamado 
copia.sh cuyo contenido es:

    !/bin/bash
    rsync -avz -e ssh root@192.168.1.100:/var/www/ /var/www/

Lo he guardado en el directorio "/etc/cron.hourly" y además le he dado 
permisos de ejecución con "chmod 700 copia.sh"
