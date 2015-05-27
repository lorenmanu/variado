# Práctica 4
*Jesús Ángel González Novez*
## Objetivos
* Comprobar rendimiento con "ab benchmark" tanto en nginx como en haproxy
* Comprobar rendimiento con httperf
* Comprobar rendimiento con OpenWebLoad

## Solución
En el guión se comenta de hacer un html sencillo, ese paso lo hice en la práctica anterior, por tanto lo omito. 

Voy a realizar las siguientes pruebas:
* 10 mediciones máquina 2 hacia máquina 1 con ab OK
* 10 mediciones máquina 2 hacia máquina 1 con httperf
* 10 mediciones máquina 2 hacia máquina 1 con openload
* 10 mediciones máquina 2 hacia máquina balanceadora(haproxy) con ab 
* 10 mediciones máquina 2 hacia máquina balanceadora(haproxy) con httperf
* 10 mediciones máquina 2 hacia máquina balanceadora(haproxy) con openload
* 10 mediciones máquina 2 hacia máquina balanceadora(nginx) con ab
* 10 mediciones máquina 2 hacia máquina balanceadora(nginx) con httperf
* 10 mediciones máquina 2 hacia máquina balanceadora(nginx) con openload

Para facilitar esta tarea haré uso de un script que itere 10 veces realizando el test y guardando los resultados al final de un fichero de texto sencillo, decir también que dado el funcionamiento de openload este lo he ejecutado sin más y lo he parado a la décima medición, es decir, no he usado el script para este último.

    #!/bin/bash
    for (( c=1; c<=10; c++ ))
    do
    ordendeltest
    done

Las ordenes que he usado son:
    
    ab -n 1000 -c 5 http://ip/ >> fichero.txt
    httperf httperf --server ip --port 80 --uri / --rate 150 --num-conn 27000 --num-call 1 --timeout 5
    openload ip 10 

Para ver los resultados he adjuntado un documento llamado graficas.html que hago uso de la api HighCharts de javascript que viene muy bien para ilustrar este tipo de cosas de forma elegante.


