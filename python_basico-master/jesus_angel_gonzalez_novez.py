#!/usr/bin/python
import datetime
class cuentaBancaria:
    titular = ""
    numero = 0
    saldo = 0
    movimientos = []

    def __init__(self,tit,num,sal):
        self.titular = tit 
        self.numero = num
        self.saldo = sal
        if sal < 0:
            self.saldo = 1000

    def ingresar(self,cantidad):
        if cantidad <= 0:
            print "----------------------------------------------"
            print "Es una cantidad erronea"
            print "----------------------------------------------"
        else:
            self.saldo += cantidad
            print "----------------------------------------------"
            print "INGRESO"
            print "Ha ingresado " + str(cantidad) + " euros"
            print "Su nuevo saldo es " + str(self.saldo) + " euros"
            print "----------------------------------------------"
            self.movimientos.append("Ingreso de " + str(cantidad) + " euros a fecha  " + str(datetime.datetime.utcnow()))
    def retirar(self,cantidad):
        if cantidad > self.saldo:
            print "No tiene suficiente saldo"
        else:
            self.saldo -= cantidad
            print "----------------------------------------------"
            print "RETIRADA"
            print "Ha retirado " + str(cantidad) + "euros con exito"
            print "Su nuevo saldo es " + str(self.saldo) + " euros"
            print "----------------------------------------------"
            self.movimientos.append("Retirada de " + str(cantidad) + " euros a fecha " + str(datetime.datetime.utcnow()))
    def saldoActual(self):
        print "----------------------------------------------"
        print "Saldo:" + str(self.saldo) + " euros"
        print "----------------------------------------------"
    def movs(self):
        print "----------------------------------------------"
        print "ULTIMOS MOVIMIENTOS y SALDO:"
        for m in self.movimientos:
            print m
        print "Saldo:" + str(self.saldo) + " euros"
        print "----------------------------------------------"
    def datosPersonales(self):
        print "----------------------------------------------"
        print "DATOS BANCARIOS"
        print "Titular:"
        print self.titular
        print "Num. Cuenta:"
        print self.numero
        print "----------------------------------------------"
cuenta = cuentaBancaria("Pepe","231231333",120)
cuenta.ingresar(10)
cuenta.retirar(20)
cuenta.saldoActual()
cuenta.movs()
cuenta.datosPersonales()
