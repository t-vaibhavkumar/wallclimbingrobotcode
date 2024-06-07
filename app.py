import tkinter as tk
import serial
import requests

ESP32_IP = '192.168.104.225'

ARDUINO_SERIAL_PORT = 'COM5'  # Replace 'COM5' with the appropriate port
ARDUINO_SERIAL_BAUDRATE = 9600

def move_up():
    arduino_serial.write(b'1')

def move_down():
    arduino_serial.write(b'2')

def hold():
    arduino_serial.write(b'3')


def cleaning():
    response = requests.get(f'http://{ESP32_IP}/cleaning')
    if response.status_code == 200:
        print("Cleaning operation initiated successfully.")
    else:
        print("Failed to initiate cleaning operation.")

# Create serial connection to Arduino
arduino_serial = serial.Serial(ARDUINO_SERIAL_PORT, ARDUINO_SERIAL_BAUDRATE)

# Create GUI window
window = tk.Tk()
window.title("Arduino Control")

# Create buttons to move up, down, hold, and for cleaning
up_button = tk.Button(window, text="Move Up", command=move_up)
up_button.pack()

down_button = tk.Button(window, text="Move Down", command=move_down)
down_button.pack()

hold_button = tk.Button(window, text="Hold", command=hold)
hold_button.pack()

cleaning_button = tk.Button(window, text="Cleaning", command=cleaning)
cleaning_button.pack()

# Run the GUI
window.mainloop()
