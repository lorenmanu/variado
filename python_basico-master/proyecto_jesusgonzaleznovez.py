#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import csv
# Jesús Ángel González Novez

# Comprobamos el número de argumentos
if len(sys.argv) < 3:
    print "Uso: python proyecto_jesusgonzaleznovez.py fichero_csv.csv fichero_html.html"
    exit(1)

# Declaramos las variables que contendrán ambos ficheros
ficheroCsv= []
ficheroHtml = []

# Probamos a abrir el fichero csv manejando posibles excepciones
try:
    ficheroCsv= csv.reader(open(sys.argv[1]))
except IOError:
    print "Error de lectura/escritura"
except ValueError:
    print "Error desconocido"

# Probamos a crear el fichero html manejando posibles excepciones
try:
    ficheroHtml = open(sys.argv[2],"w")
except IOError:
    print "Error de lectura/escritura"
except:
    print "Error desconocido"

# Para no tener problemas con acentos o ñ
ficheroHtml.write('<meta charset="utf-8">')

# Escribimos código html para crear la tabla en el fichero html
ficheroHtml.write('<table border="1">')
ficheroHtml.write('<tr bgcolor="red">')
ficheroHtml.write('<th>Nombre</th><th>Apellido1</th><th>Apellido2</th><th>Email</th>')
ficheroHtml.write('</tr>')

numeroDeFila = 0

# Iteramos por cada una de las filas del fichero csv
for fila in ficheroCsv:
    # Escribimos codigo html para cada fila de la tabla
    ficheroHtml.write('<tr>')
    # Si estamos en una fila par el color de fondo de la celda
    # lo ponemos azul, en caso contrario lo ponemos verde
    if numeroDeFila%2 == 0:
        # Iteramos por cada una de las columnas de una fila del csv
        # y escribimos el codigo correspondiente en html
        for columna in fila:
            ficheroHtml.write('<td bgcolor="blue">' + columna + '</td>')
    else:
        # Iteramos por cada una de las columnas de una fila del csv
        # y escribimos el codigo correspondiente en html
        for columna in fila:
            ficheroHtml.write( '<td bgcolor="green">' + columna + '</td>')
    ficheroHtml.write('</tr>')# Cerramos la fila
    # Incrementamos en uno la fila en la que nos encontramos
    numeroDeFila += 1

# Cerramos la tabla en html
ficheroHtml.write('</table>') 

# Mostramos por consola que se ha creado con exito el fichero html con la tabla
# de n filas
print "Tabla en HTML de " + str(numeroDeFila) + " filas creada con éxito."
exit(0)


