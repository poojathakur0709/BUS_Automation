#/dev/ttyACM0
import serial
ser = serial.Serial('COM4',9600,timeout=1)
ser.flush()
while True:###yeh run time m chlegaa
    if ser.in_waiting > 0:
        line = ser.readline()
        print(line)
        if line.find(b'Fuel Centre') != -1:
            a = line.find(b'Fuel Centre')
            a = a+11
            print(line[a:a+3])#1-7
            #change value of redar accordig  to value received from sensor
        if line.find(b'Humidity') != -1:
            b = line.find(b'Humidity')
            b = b+9
            print(line[b:b+3])
            #Humidity value received
        if line.find(b'Temperature') != -1:
            c = line.find(b'Temperature')
            c = c+12
            print(line[c:c+3])
            #Temperature value received
        ###Gate ON Gate OFF Theft ON Theft OFF send dataa
        
        
        
        if line.find(b'Distance BackUpper') != -1:
            d = line.find(b'Distance BackUpper')
            d = d+18
            print(line[d:d+3])
            #Distance value received
        if line.find(b'Distance BackDown') != -1:
            e = line.find(b'Distance BackDown ')
            e = e+18
            print(line[e:e+3])
            #Distance value received
        if line.find(b'Distance BackCentre') != -1:
            f = line.find(b'Distance BackCentre')
            f = f+18
            print(line[f:f+3])
            #Distance value received
        if line.find(b'Distance BackUpperUpper') != -1:
            g = line.find(b'Distance BackUpperUpper')
            g = g+21
            print(line[g:g+3])
            #Distance value received
        if line.find(b'Distance BackDownDown') != -1:
            h = line.find(b'Distance BackDownDown')
            h = h+21
            print(line[h:h+3])#30 -50
            #Distance value received
        if line.find(b'Weight') != -1:
            i = line.find(b'Weight')
            i = i+7
            print(line[i:i+3])#kg value
            #Weight value received
            
