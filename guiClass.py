
from Tkinter import *

class Application(Frame):
	def __init__(self,master):
                
                self.clicks = 0
                 
                Frame.__init__(self,master)
                self.grid()
		self.makeWidgets()

	def makeWidgets(self):
		self.lbl = Label(self, text = "brain surgery.")
		self.lbl.grid()

		self.btn0 = Button(self, text = "what is your name?")
		self.btn0.grid()

		self.btn1 = Button(self)
		self.btn1.grid()
		self.btn1.configure(text = "what is your quest?")

		self.btn2 = Button(self)
		self.btn2.grid()
		self.btn2["text"] = "what is the capital of Kiributi?"

                self.btn2["command"] = self.updateClickCount

        def updateClickCount(self):
                self.clicks += 3
                self.lbl["text"] = str(self.clicks) + " odd fellows performing brain surgery."

if __name__ == '__main__':
	root = Tk()
	root.title("Python + Tkinter in Linux")
	root.geometry("640x480")

        app = Application(root)

	root.mainloop()

