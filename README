Protocol - two-way-communication between pi and arduino

Serial 'input' are sent from pi to arduino, and 'output' are sent from arduino to pi

Examples of commands to the arduino are first described, followed by
an example of how a python script on a pi could send a request to the arduino
and then receive a response.

Ex 1: Turn on burglar alarm
Input string "1"
Output string "Burglar alarm on"

Ex 2: Turn off burglar alarm
Input string "2"
Output string "Burglar alarm off"

Ex 3: Turn on fire alarm
Input string "3"
Output string "Fire alarm on"

Ex 4: Turn off fire alarm
Input string "4"
Output string "Fire alarm off"

Ex 5: Turn on lamp outside
Input string "5"
Output string "Lamp outside on"

Ex 6: Turn off lamp outside
Input string "6"
Output string "Lamp outside off"

Ex 7: Turn on lamp inside
Input string "7"
Output string "Lamp inside on"

Ex 8: Turn off lamp inside
Input string "8"
Output string "Lamp outside off"

Ex 9: Check if door is open
Input string "9"
Output string "on" or "off"

Ex 10: Check temperature
Input string "10"
Output celsius in string

Ex 11: Turn on radiator
Input string "11"
Output string "Radiator is on"

Ex 12: Turn off radiator
Input string "12"
Output string "Radiator is off"

If input to arduino doesn't match any of these commands:
Output string "Not known command"


Example of python script run from a Raspberry Pi 3:
import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
ser.write('3') #Turns on fire alarm
print(ser.readLine()) #Prints out respons from arduino
