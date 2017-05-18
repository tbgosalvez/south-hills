from Tkinter import *

root = Tk()
root.title("Python + Tkinter in Linux")
root.geometry("640x480")

mainFrame = Frame(root)
mainFrame.grid()

lbl = Label(mainFrame, text = "brain surgery.")
lbl.grid()

btn0 = Button(mainFrame, text = "what is your name?")
btn0.grid()

btn1 = Button(mainFrame)
btn1.grid()
btn1.configure(text = "what is your quest?")

btn2 = Button(mainFrame)
btn2.grid()
btn2["text"] = "what is the capital of Kiributi?"

root.mainloop()

