import serial,time
arduino=serial.Serial('COM3',9600,timeout=.1)//timeout is given so that the connection stabilizes
time.sleep(1)
while True:
    print("Enter position of upper and lower servo")
    dat=input()
    data=bytes(dat.encode(encoding='utf-8', errors='strict'))
    arduino.write(data)

