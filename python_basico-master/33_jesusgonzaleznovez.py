#!/usr/bin/python
palabra = "inicio"
lista = []
while palabra != "Basta" and palabra != "":
	palabra = raw_input("Introduzca palabra:")
	if palabra != "Basta" and palabra != "":
		lista.append(palabra)
	print lista
