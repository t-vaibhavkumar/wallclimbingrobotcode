import tkinter as tk

def send_command(command):
    pass

def move_up():
    send_command('1')  # Send '1' to move up

def move_down():
    send_command('2')  # Send '2' to move down

def hold():
    send_command('3') # Send '3' to hold

# Create serial connection to Arduino
 # Replace 'COM3' with the appropriate port

# Create GUI window
window = tk.Tk()
window.title("Arduino Control")

# Create buttons to move up and down'
up_button = tk.Button(window, text="Move Up",font=("Jetbrain mono",24), command=move_up)
up_button.pack(padx=20,pady=20)

down_button = tk.Button(window, text="Move Down",font=("Jetbrain mono",24), command=move_down)
down_button.pack(padx=20,pady=20)

hold_button = tk.Button(window, text="Hold",font=("Jetbrain mono",24), command=hold)
hold_button.pack(padx=20,pady=20)

# Run the GUI
window.mainloop()
