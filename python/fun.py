def input_lines():
    lines = []
    line = ""
    comb = chr(1)
    while line != comb:
        line = input()
        if line:
            lines.append(line)
    lines.pop(-1)
    return lines


def writeFile(lines, name):
    file = open(name, "w")
    for i in range(0, len(lines)):
        file.write(lines[i])
        if i != len(lines) - 1:
            file.write("\n")
    file.close()


def split_for_two(lines, lines1, lines2):
    for i in range(0, len(lines)):
        if i % 2 != 0:
            lines1.append(lines[i])
        else:
            lines2.append(lines[i])


def task_with1(lines1):
    for i in range(0, len(lines1)):
        for j in range(i + 1, len(lines1)):
            if lines1[i][0].lower() > lines1[j][0].lower():
                lines1[i], lines1[j] = lines1[j], lines1[i]
            elif lines1[i][0].lower() == lines1[j][0].lower():
                for k in range(1, len(lines1)):
                    if lines1[i][k].lower() > lines1[j][k].lower() or lines1[j][k] != ' ':
                        break
                lines1[i], lines1[j] = lines1[j], lines1[i]
    return lines1


def task_with2(lines2, n):
    words = []
    for m in range(0, n):
        words = lines2[m].split()
        for i in range(0, len(words)):
            for j in range(i + 1, len(words)):
                if words[i][0].lower() > words[j][0].lower():
                    words[i], words[j] = words[j], words[i]
                elif words[i][0].lower() == words[j][0].lower():
                    for k in range(1, len(words[i])):
                        if words[i][k].lower() > words[j][k].lower() or words[j][k] != ' ':
                            break
                    words[i], words[j] = words[j], words[i]
        lines2[m] = " ".join(words)
    return lines2


def outText(name):
    file = open(name, "r")
    while True:
        line = file.readline()
        if not line:
            break
        print(line.strip())
    file.close()

