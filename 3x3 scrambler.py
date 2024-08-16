import tkinter as tk
from tkinter import messagebox
import random

# Initialize global variables
times = []
total_time = 0
scramble_moves = []

def submit_time():
    global total_time
    try:
        time = float(entry.get())
        times.append(time)
        total_time += time
        entry.delete(0, tk.END)  # Clear the entry field
        if len(times) >= 5:
            calculate_results()
        # Generate a new scramble after submitting the time
        generate_moves()
    except ValueError:
        messagebox.showerror("Invalid input", "Please enter a valid number.")

def calculate_results():
    if len(times) > 2:
        times.remove(max(times))
        times.remove(min(times))
        remaining_time_sum = sum(times)
        Avg = remaining_time_sum / 3
        messagebox.showinfo("Results", f"Average of 5: {Avg:.2f}")
    else:
        messagebox.showwarning("Not enough data", "Not enough times to remove min and max.")

def generate_moves():
    global scramble_moves
    moves = ['R', 'L', 'U', 'D', 'F', 'B', 'R2', 'L2', 'U2', 'D2', 'F2', 'B2', "R'", "L'", "U'", "D'", "F'", "B'"]
    scramble_moves = []
    
    while len(scramble_moves) < 17:
        move = random.choice(moves)
        
        # Ensure that no move is adjacent to its inverse or duplicate
        if scramble_moves:
            last_move = scramble_moves[-1]
            if (move in [last_move, last_move + "'", last_move + "2"]) or \
               (last_move in [move, move + "'", move + "2"]):
                continue
        
        scramble_moves.append(move)
    
    scramble_label.config(text="Scramble: " + " ".join(scramble_moves))

# Setup the main window
root = tk.Tk()
root.title("Time Entry")

# Create widgets
label = tk.Label(root, text="Enter time:")
label.pack(pady=10)

entry = tk.Entry(root)
entry.pack(pady=5)

submit_button = tk.Button(root, text="Submit Time", command=submit_time)
submit_button.pack(pady=10)

scramble_label = tk.Label(root, text="Scramble: ")
scramble_label.pack(pady=10)

generate_moves()  # Generate initial moves when the GUI starts

# Run the GUI event loop
root.mainloop()
