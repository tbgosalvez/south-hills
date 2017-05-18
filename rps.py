#python 3.4
#import tkinter
#python 2.7
from Tkinter import *
from random import randint

class Player(object):
    rps = {'rock':'scissors', 'scissors':'paper', 'paper':'rock'}

    def __init__(self):
        self.choice = StringVar()
        self.points = 0
        self.choice.set('paper')


class Application(Frame):
    def __init__(self,master):
        self.curRound = 1

        self.you = Player()
        self.ai = Player()
        
        Frame.__init__(self,master)
        self.grid()
        self.makeWidgets()

    def makeWidgets(self):
        nRow = 0

        self.lblChoice = Label(self, 
                    text="pick something. best out of 5 wins."
                    ).grid(row=nRow)

        nRow+=2
        Radiobutton(self,
                text="Rock",
                variable=self.you.choice,
                value="rock"
                ).grid(row=nRow)

        nRow+=1
        Radiobutton(self,
                text="Paper",
                variable=self.you.choice,
                value='paper'
                ).grid(row=nRow)

        nRow+=1
        Radiobutton(self,
                text="Scissors",
                variable=self.you.choice,
                value='scissors'
                ).grid(row=nRow)

        nRow+=2
        self.lblMsg = Label(self,text="start!")
        self.lblMsg.grid()

        nRow+=1
        self.btnGo = Button(self,text="go")
        self.btnGo.grid()
        self.btnGo["command"] = self.updateScore
            
    def updateScore(self):
        strMsg = ""

        # make the ai "choose" every time
        listKeys = Player.rps.keys()
        app.ai.choice.set(listKeys[randint(0,len(Player.rps.keys())-1)])

        if(self.you.choice.get() == Player.rps.get(self.ai.choice.get())):
            self.ai.points += 1
            strMsg = "AI's "+self.ai.choice.get()+" beats your "+self.you.choice.get()
        elif(self.you.choice.get() == self.ai.choice.get()):
            strMsg = "draw!"
        else:
            self.you.points += 1
            strMsg = "Your "+self.you.choice.get()+" beats AI's "+self.ai.choice.get()
        strMsg += "\nScore:\n"
        strMsg += "AI: "+(str(self.ai.points))+"\n"
        strMsg += "You: "+(str(self.you.points))+"\n"

        self.lblMsg["text"] = strMsg       
        print(strMsg)

        # calc winner, i.e. maximum, after 5 rounds
        dictScores = {self.you.points:'you',self.ai.points:'ai'}

        if(self.curRound > 4):
            print('the winner: '+ dictScores.get(max(dictScores.keys())))

        self.curRound += 1


if __name__ == '__main__':

    root = Tk()
    root.title("Rock, Paper, Scissors. No Spock.")
    root.geometry("320x240")

    app = Application(root)

    root.mainloop()

