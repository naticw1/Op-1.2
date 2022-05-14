from foo import *

fileName1 = "File1.dat"
fileName2 = "File2.dat"
fileName3 = "gg.dat"
size = file1(fileName1)
listFile1 = readFile1(fileName1, size)
size2 = file2(fileName2, listFile1)
outFile1(fileName1, size)
outFile2(fileName2, size2)
size3 = removeAmpoule(fileName2, fileName3, size2)
outFile2(fileName2, size3)
