#!/usr/bin/python
def concatena(cad_base, *otras):
    for o in otras:
        cad_base += " " + o
    print cad_base

concatena("Base","hola","adios")
