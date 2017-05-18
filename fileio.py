with open('bibfile.txt', 'rb') as inFile:
    print inFile.read(7)
    print inFile.read(4)
    print inFile.readline()
    inFile.close()

with open('out.txt', 'wb') as outFile:
    outFile.write('[Classes for Wednesdays]\n')
    outFile.write('python in rm22\n')
    outFile.write('technical presentations in rm18 or rm19\n')
    outFile.write('capstone project in [anywhere]\n')
    outFile.write('business introduction in rm 23\n')
    outFile.write('ethical hacking in rm 19, i think\n')
    outFile.close()
