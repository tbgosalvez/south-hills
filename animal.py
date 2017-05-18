#
# python 2.7
#

class Animal:
    def __init__(self, nn='homer'):
        self.name = nn
        self.data = [0, 'simpson']
    
    def speak(self):
        print 'i am an animal, rather than a fungus, as opposed to a plant.'
        print 'ich bin nicht ein Fungus, sondern ein Tier.'
        print 'auch, ich heisse \'',self.name,'\'.\n'

class Dog(Animal):
    def __init__(self, nn='fido'):
        self.name = nn

    def speak(self):
        print 'my name is ',self.name,'.'
        print 'also, woof.\n'

class Cat(Animal):
    def __init__(self, nn='morris'):
        self.name = nn

    def speak(self):
        print 'my name is ',self.name,'.'
        print 'also, meow.\n'

class Metal(Animal):
    def __init__(self, nn='0xC00F'):
        self.name = nn

    def speak(self):
        print 'I AM ROBOT THING'
        print 'WITH IDENTIFIER =',self.name
        print 'AND WHEELS'

if __name__=='__main__':
    print

    aaa = Animal('bart')
    aaa.speak()
    
    bbb = Animal()
    bbb.speak()

    ddd = Dog()
    ddd.speak()

    ccc = Cat()
    ccc.speak()

    mmm = Metal()
    mmm.speak()
