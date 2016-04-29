import socket

##from tkinter import *
##
##root = Tk()
##root.title("Hornet Drone Terminal")
##root.geometry("100x100")
##
##app = Frame(root)
##app.grid()
##
##button1 = Button(app, text = "Lights")
##button1.grid()
##
##button2 = Button(app, text = "Camera")
##button2.grid()
##
##root.mainloop()
##





UDP_IP = "143.215.110.127"
UDP_PORT = 5005

while True:
    MESSAGE = bytearray()
    MESSAGE1 = input("Enter the message \n")

    MESSAGE.extend(map(ord,MESSAGE1))

    print("UDP target IP:", UDP_IP)
    print("UDP target port:", UDP_PORT)
    print("message:", MESSAGE)

    sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP

    sock.sendto( MESSAGE, (UDP_IP, UDP_PORT))
