# defs.py
# -*- coding: latin-1 -*-
# using Python 2.7

inFile = open('bibfile.txt', 'rb')
outFile = open('out.txt', 'wb')
appFile = open('appendations.txt', 'a')

def askLines():
    num = int(raw_input('Wieviele Linien möchtest du aus dem File?'))
    for i in range(num):
        print inFile.readline()

def outputLines():
    num = int(raw_input('Wieviele Linien möchtest du aus dem File?'))
    for i in range(num):
        outFile.write(inFile.readline())

def appendLines():
    aa = raw_input('Gib uns eine Frase oder ein Satz.')
    while aa.lower() != 'q':
        appFile.write(aa+'\n')
        aa = raw_input('Gib uns eine Frase oder ein Satz.')

def askFred():
	from testClass import ask as HUMAN
	fred = HUMAN()
	fred.greet()

if __name__ == '__main__':
    #askLines()
    #outputLines()
    #appendLines()
    askFred()

appFile.close()
outFile.close()
inFile.close()
