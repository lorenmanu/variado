#!/usr/bin/python
print "Tablas de multiplicar"
print "---------------------"
for i in range(2,10):
	print " "
	print "-------------------------"
	print "Tabla del " + str(i) + ":"
	print "-------------------------"
	for j in range(1,11):
		print str(i) + "x" + str(j) + "=" + str(i*j)
