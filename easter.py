phrase = 'I love programming'
strLove = phrase[2:6]+'\n'
strFragment = phrase[4:8]+'\n'
strProg = phrase[7:]+'\n'
strBegin = phrase[:6]+'\n'

print strLove+strFragment+strProg+strBegin

tupMonths = ('Jan','feb','mar','apr','may','jun',
        'jul','aug','sep','oct','nov','dec')

print "original tuple of months\n"
for a in tupMonths:
    print a

liMonths = list(tupMonths)
liMonths[3] = 'showers'

print '\nnew list of months\n'
for a in liMonths:
    print a

def showMonths():
    tupMonths = ('Jan','feb','mar','apr','may','jun',
            'jul','aug','sep','oct','nov','dec')

    print "original tuple of months\n"
    for a in tupMonths:
        print a

    liMonths = list(tupMonths)
    liMonths[3] = 'showers'

    print 'new list of months\n'
    for a in liMonths:
        print a

print 'calling showMonths()\n'
showMonths()

ss = 17
if ss == 17:
    print 'you found the holy grail\n'
elif ss < 17:
    print 'you stumbled upon Tim\n'
else:
    print 'what is the capital of Assyria?'

dictMonths = {}
dictMonths = dictMonths.fromkeys(range(0,12))
for k in range(0,12):
    dictMonths[k] = tupMonths[k]

print 'dictionary:'
print dictMonths
print 'human-readable:'

strOutput = ['%s: %s' % (k,v) for k,v in dictMonths.items()]

for a in strOutput:
    print a
