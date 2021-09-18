import socket
import time
import imutils
import base64
import cv2

UDP_IP = "127.0.0.1"
UDP_PORT = 5005

print("UDP target IP: %s" % UDP_IP)
print("UDP target port: %s" % UDP_PORT)


BUFF_SIZE = 65536


#counter = 0
sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
#sock.setsockopt(socket.SOL_SOCKET, SO_RCVBUF, BUFF_SIZE)
                     
im = cv2.imread("./im.jpg")
im = imutils.resize(im, 800)
encoded, buffer = cv2.imencode('.jpg', im, [cv2.IMWRITE_JPEG_QUALITY, 80])
message = base64.b64encode(buffer)

#imbytes = bytearray(im)
          
while(True):
	#message = bytes(str(counter), 'utf-8')
	#print(message)
	sock.sendto(message, (UDP_IP, UDP_PORT))
	#counter += 1
	time.sleep(1)
