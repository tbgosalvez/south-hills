

from Tkinter import *

class Application(Frame):
	def __init__(self,master):
		self.hasKetchup = BooleanVar()
		self.hasMustard = BooleanVar()

		self.hasMayo = BooleanVar()
		self.hasPickles = BooleanVar()
		self.hasBacon = BooleanVar()

		self.cheese = StringVar()

                self.dictToppings = { 
			"ketchup":self.hasKetchup,
			"mustard":self.hasMustard,
			"mayonnaise":self.hasMayo,
			"pickles":self.hasPickles,
			"hickory-smoked bacon":self.hasBacon
		}

		# gui stuff
                Frame.__init__(self,master)
                self.grid()
		self.makeWidgets()

	def makeWidgets(self):
		self.lblOrderHeader = Label(self, text = "you can haz burger:")
		self.lblOrderHeader.grid(row=0,column=4)

		self.lblOrder = Label(self, text = "food:")
		self.lblOrder.grid(row=0,column=4,rowspan=4,sticky=S)

		self.lbl = Label(self, text = "Your Legal Given Name:")
		self.lbl.grid(row=0, column=0, sticky = W)

		self.txtName = Entry(self)
		self.txtName.grid(row=0, column=2, columnspan=2, sticky=E)

		nRow = 0
		for k,v in self.dictToppings.items():
			nRow+=1
			Checkbutton(self, 
					text=k, 
					variable=v, 
					command=self.updateOrder
				).grid(row=nRow,column=1)

		nRow+=1
		Radiobutton(self,
				text="cheddar",
				variable=self.cheese,
				value="cheddar cheese",
				command=self.updateOrder
			).grid(row=nRow,column=1)

		nRow+=1
		Radiobutton(self,
				text="havarti",
				variable=self.cheese,
				value="havarti cheese",
				command=self.updateOrder
			).grid(row=nRow,column=1)

		self.btnSubmit = Button(self, text = "Order you a ham-burger")
		self.btnSubmit.grid(row=nRow, column=2, sticky=S)
		self.btnSubmit["command"] = self.orderFood


	def orderFood(self):
		self.btnSubmit["text"] = "your food is on its way!\n"

	def updateOrder(self):
		strToppings = ""
		for t,v in self.dictToppings.items():
			if(v.get()):
				strToppings += str(t+"\n")
		
		strToppings+=self.cheese.get()
		
		self.lblOrder["text"] = strToppings

        def updateClickCount(self):
                self.clicks += 3
                self.lbl["text"] = str(self.clicks) + " odd fellows performing brain surgery."

if __name__ == '__main__':
	root = Tk()
	root.title("Python + Tkinter in Linux")
	root.geometry("640x480")

        app = Application(root)

	root.mainloop()

