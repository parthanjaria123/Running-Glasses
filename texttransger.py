import serial#.tools.list_ports
import gmplot

#initialize the variable for the connected serial port
#to find the available serial ports use print(list(serial.tools.list_ports.comports()))

serial_port = 'COM5'
baud_rate = 9600
write_to_file_path = "test.txt"

z = 1

latitude_list = []
longitude_list = []

#output_file = open(write_to_file_path, "w+");
ser = serial.Serial(serial_port,baud_rate)
while True:
    line = ser.readline()
    line = line.decode("utf - 8")
    line = float(line)
    #output_file.write(line)
    if(int(line)==1000):
        break;
    elif(z%2==0):
        longitude_list.append(line)
        print(line)
        z+=1
    else:
        latitude_list.append(line)
        print(line)
        z+=1

#var_list = []


#file = open(test.txt)

'''for var in file:
    var = var.strip()
    var_list.append(var)'''

'''latitude_list = []
longitude_list = []'''

'''latitude_list.append(var_list[0])
latitude_list.append(var_list[2])
longitude_list.append(var_list[1])
longitude_list.append(var_list[3])'''

gmap3 = gmplot.GoogleMapPlotter(latitude_list[0],longitude_list[0],13)

#gmap3.scatter(latitude_list[0],longitude_list[0],'# FF0000',size = 40,marker= False)

gmap3.plot(latitude_list,longitude_list,'cornflowerblue', edge_width = 2.5)

gmap3.draw("C:\\Users\\anand\\Desktop\\maps.html")

print("Done")
