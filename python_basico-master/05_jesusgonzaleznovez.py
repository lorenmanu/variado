import urllib                                       
sock = urllib.urlopen("http://swad.ugr.es") 
htmlSource = sock.read()                            
sock.close()                                        
print htmlSource                                   
fichero = open("salida.txt","w")
fichero.write(htmlSource)
