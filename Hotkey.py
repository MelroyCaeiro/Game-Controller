import serial
import pyautogui, time
import random as rd
import sys
pyautogui.FAILSAFE= True

def Hotkey():
    pyautogui.hotkey("ctrl", "shift", "esc")

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
        Hotkey()
        print("go")
    else:
        print("stop")
        pass

    #time.sleep(0.2) # for CS
