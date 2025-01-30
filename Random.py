import tkinter as tk
from tkinter import messagebox
import random
import time

class ClickTheButtonGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Click the Button Game")
        self.root.geometry("400x300")
        
        self.score = 0
        self.time_left = 30  # 30 seconds to play
        self.button_size = 80
        
        # Score label
        self.score_label = tk.Label(root, text=f"Score: {self.score}", font=("Arial", 16))
        self.score_label.pack(pady=10)
        
        # Timer label
        self.timer_label = tk.Label(root, text=f"Time Left: {self.time_left}", font=("Arial", 16))
        self.timer_label.pack(pady=10)
        
        # Clickable button
        self.button = tk.Button(root, text="Click Me!", bg="lightblue", font=("Arial", 14), command=self.increase_score)
        self.button.place(x=random.randint(0, 320), y=random.randint(50, 220))
        
        # Start the timer
        self.update_timer()
    
    def increase_score(self):
        """Increase the score and move the button to a new random position."""
        self.score += 1
        self.score_label.config(text=f"Score: {self.score}")
        self.move_button()
    
    def move_button(self):
        """Move the button to a random position on the screen."""
        new_x = random.randint(0, self.root.winfo_width() - self.button_size)
        new_y = random.randint(50, self.root.winfo_height() - self.button_size)
        self.button.place(x=new_x, y=new_y)
    
    def update_timer(self):
        """Update the timer every second and end the game when time runs out."""
        if self.time_left > 0:
            self.time_left -= 1
            self.timer_label.config(text=f"Time Left: {self.time_left}")
            self.root.after(1000, self.update_timer)  # Call this function again after 1 second
        else:
            self.end_game()
    
    def end_game(self):
        """End the game and show the final score."""
        self.button.config(state=tk.DISABLED)  # Disable the button
        messagebox.showinfo("Game Over", f"Time's up! Your final score is {self.score}.")
        self.root.quit()

# Create the main window
root = tk.Tk()
game = ClickTheButtonGame(root)

# Run the game
root.mainloop()