#/usr/bin/env/python3 
#UDP Client

import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
text = 'Hello World'
data = text.encode('ascii')
sock.sendto(data, ('127.0.0.1', 1025))
data, address = sock.recvfrom(65538) 




#text = data.decode('ascii')
#print('The server {} replied {}'.format(address, text))