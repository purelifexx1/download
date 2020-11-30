#/usr/bin/env/python3 
 #Python UDP Listener, listening on localhost 1025, change address 
 # to listen on other ip/port combos. 
import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('127.0.0.1', 1234))

while True:
    data, address = sock.recvfrom(65538)
    text=[]
    for i in range(0,data.size()):
        text.append(bytes.fromhex(data(i)))
    print('Connection from Client {}'.format(text))
    text = 'Your data was {} bytes long'.format(len(data))
    data = text.encode('ascii')
    sock.sendto(data, address)
