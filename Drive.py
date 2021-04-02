import serial
import pyautogui, time
import random as rd
import sys
pyautogui.FAILSAFE= True

def Go():
    pyautogui.keyDown("up")

def Stop():
    pyautogui.keyUp("up")

try:
    arduino = serial.Serial("COM3", timeout=1, baudrate=9600)
except:
    print('Please check the port')

time.sleep(6)

while True:
    lr = arduino.readline()
    nl = lr.decode("utf-8")
    ll = int(nl)

    cond = (ll<20 or ll>2000)

    if cond==True:
        Go()
        print("go")
    else:
        Stop()
        print("stop")
        pass

    #time.sleep(0.2) # for CS
