from ClassOne import Calculator as calc

'''cc = calc()
cc.add(8)
print cc.getCurrent()
'''

if __name__ == '__main__':
    cc = calc()

    usrIn = input('Type a number, \'q\' to quit')
    
    if usrIn != ('q'):
        usrIn = int(usrIn)
    
    while usrIn != ('q'):
        cc.add(usrIn)
        print cc.getCurrent()
        usrIn = input('Type a number, \'q\' to quit')
        
        if usrIn != 'q':
            usrIn = int(usrIn)
