import socket
import smbus
import time

bus = smbus.SMBus(1)
address = 0x0e

def writeNumber(value):
    bus.write_byte(address, value)
    # bus.write_byte_data(address, 0, value)
    return -1


if os.name != "nt":
    import fcntl
    import struct
    def get_interface_ip(ifname):
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        return socket.inet_ntoa(fcntl.ioctl(
                s.fileno(),
                0x8915,  # SIOCGIFADDR
                struct.pack('256s', bytes(ifname[:15], 'utf-8'))
                # Python 2.7: remove the second argument for the bytes call
            )[20:24])

def get_lan_ip():
    ip = socket.gethostbyname(socket.gethostname())
    if ip.startswith("127.") and os.name != "nt":
        interfaces = ["eth0","eth1","eth2","wlan0","wlan1","wifi0","ath0","ath1","ppp0"]
        for ifname in interfaces:
            try:
                ip = get_interface_ip(ifname)
                break;
            except IOError:
                pass
    return ip

UDP_IP = get_lan_ip()
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    print("received message:", data, addr)
    received = data
    if received == b'option1':
        print("Command Received")
        writeNumber(48)
    if received == b'option2':
        writeNumber(49)
    if reveiced == b'option3':
        writeNumber(50)
    if received == b'option4':
        writeNumber(51)
    if received == b'option5':
        writeNumber(52)
    if received == b'option6':
        writeNumber(53)

        


