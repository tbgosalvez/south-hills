# ClassOne.py

class Calculator(object):
    def __init__(self):
        self.current = 0
    def add(self, amt):
        self.current += amt
    def sub(self, amt):
        self.current -= amt
    def mul(self, a):
        self.current *= a
    def div(self, a):
        self.current /= a
    def getCurrent(self):
        return self.current

if __name__ == "__main__":
    print 'this module defines the Calculator class.'
    print 'test:'
    cc = Calculator()
    cc.add(5)
    print '\tadd(5) => '+str(cc.getCurrent())
    cc.sub(1)
    print '\tsub(1) => '+ str(cc.getCurrent())
    cc.mul(3)
    print '\tmul(3) => '+ str(cc.getCurrent())
    cc.div(4)
    print '\tdiv(4) => '+ str(cc.getCurrent())
