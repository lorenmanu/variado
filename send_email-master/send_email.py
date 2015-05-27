import smtplib
fromaddr = 'tudireccion@gmail.com'
toaddrs = 'destino@dominio.com'
msg = 'prueba'
server = smtplib.SMTP('smtp.gmail.com:587')
server.starttls()
server.login('tudireccion','tupassword')
server.sendmail(fromaddr,toaddrs,msg)
server.quit()
