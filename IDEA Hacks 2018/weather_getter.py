from time import sleep
import urllib.request, json
import serial

location = input("Type your destination city\n")
print(location)

with urllib.request.urlopen("http://api.openweathermap.org/data/2.5/weather?q="+ location +"&APPID=905c74d7ddaa1cb4c409fab5c93c4cd1") as url:
	data = json.loads(url.read().decode())
	rain = data["weather"][0]["main"]
	temp = (9/5)*(data["main"]["temp"]-273)+32
	print(rain, temp)

isRain = False
if rain == "Rain" or rain == "Drizzle":
	isRain = True

file = open("data.txt", "w")
file.write("%s %s"%(isRain, temp))

ser = serial.Serial('/dev/tty.COM3', 9600)
counter = 32
while True:
	counter += 1
	ser.write(chr(counter).encode())
	print(ser.readline())
	sleep(.1)
	if counter == 255:
		break

ser.close()