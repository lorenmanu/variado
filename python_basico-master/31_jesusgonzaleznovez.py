#!/usr/bin/python
a = raw_input("a:")
b = raw_input("b:")
if a.isdigit() == True: 
	if b.isdigit() == True:
		if int(a) > int(b):
			print "a > b"
		if int(a) == int(b):
			print "a == b"
		if int(a) < int(b):
			print "a < b"
if a.isdigit() == False:
	print "a no es un numero"
if b.isdigit() == False:
	print "b no es un numero"
