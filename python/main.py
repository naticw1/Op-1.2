from fun import *
print("Enter lines(Press ctr + a to save work")
n = int(input("Enter n :"))
inFileName = "text"
FileName1 = "text-1"
FileName2 = "text-2"
ch_FileName1 = "changed-text-1"
ch_FileName2 = "changet-text-2"
lines = input_lines()
writeFile(lines, inFileName)
lines1 = []
lines2 = []
split_for_two(lines, lines1, lines2)
writeFile(lines1, FileName1)
writeFile(lines2, FileName2)
ch_lines1 = task_with1(lines1)
ch_lines2 = task_with2(lines2, n)
writeFile(ch_lines1, ch_FileName1)
writeFile(ch_lines2, ch_FileName2)
print("\nOriginal text :")
outText(inFileName)
print("\nText 1 :")
outText(FileName1)
print("\nText 2 :")
outText(FileName2)
print("\nChanged text 1 :")
outText(ch_FileName1)
print("\nChanged text 2 :")
outText(ch_FileName2)
