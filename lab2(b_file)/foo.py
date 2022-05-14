import pickle
import os


class Ampoule:# клас для першого файлу
    def __init__(self, name, timeAfter, expirationDate):
        self.name = name
        self.timeAfter = timeAfter
        self.expirationDate = expirationDate


class Info:#клас для другого файлу
    def __init__(self, name1, timeOpening, timeToUse):
        self.name1 = name1
        self.timeOpening = timeOpening
        self.timeToUse = timeToUse


def file1(fileName1):#дії та запис в перший файл
    print(fileName1 + ":\n")
    flag = 'y'
    size = 0
    with open(fileName1, "wb") as file:
        while flag == 'y':
            name_ = input("enter ampoule name :")
            name_ = verName(name_)
            time_After = input("expiration date after opening :")
            time_After = verTimeAfeter(time_After)
            expiration_Date = input("expiration date :")
            expiration_Date = verExp(expiration_Date)
            b = Ampoule(name_, time_After, expiration_Date)
            pickle.dump(b, file)
            flag = input("continue ? y/n : ")
            size += 1
        file.close()
    return size


def verName(name):#перевірка імені
    while len(name) > 20 or len(name) < 1:
        name = input("Please , enter ampoule name again :")
    return name


def verTimeAfeter(time):#перевірка терміну зберігання на формат
    if len(time) == 5:
        hour = verHour(time[0:2])
        min = verMin(time[3:5])
    while len(time) != 5 or time[2] != ':' or min or hour:
        time = input("Enter correct time in format HH:MM:")
        if len(time) == 5:
            hour = verHour(time[0:2])
            min = verMin(time[3:5])
    return time


def verHour(hour):#години на формат
    flag = False
    h = int(hour)
    if h < 0 or h > 24:
        flag = True
    return flag


def verMin(minut):#хвилини на формат
    flag = False
    m = int(minut)
    if m < 0 or m > 59:
        flag = True
    return flag


def verExp(year):#перевірка дати
    while int(year) < 0 or int(year) > 100:
        year = input("enter Expiration Date again :")
    return year


def outFile1(filename1, size):#виводимо вміст першого файлу
    print(filename1 + ":\n")
    ampoule = []
    with open(filename1, "rb") as file:
        for i in range(size):
            ampoule.append(pickle.load(file))
            line = ampoule[i].name + ", " + ampoule[i].timeAfter + ", " + ampoule[i].expirationDate + ";"
            print(line + "\n")
    file.close()


def readFile1(filename1, size):#зчитуємо вміст файлу 1 в лист
    text = []
    with open(filename1, "rb") as file:
        for i in range(size):
            text.append(pickle.load(file))
    file.close()
    return text


def file2(filename2, fileText1):#дії та запис даних в файл 2
    print(filename2 + ":\n")
    flag = 'y'
    size = 0
    with open(filename2, "wb") as file:
        while flag == 'y':
            number = 0
            name_ = input("enter ampoule name :")
            name_ = checkInList(fileText1, name_)
            number = getNumber1(fileText1, name_, number)
            time_Opening = input("enter time of opening :")
            time_Opening = verTimeAfeter(time_Opening)
            timeToFile2 = getTime(time_Opening, fileText1[number].timeAfter)
            a = Info(name_, time_Opening, timeToFile2)
            pickle.dump(a, file)
            size += 1
            flag = input("continue ? y/n : ")
    file.close()
    return size


def checkInList(fileText1, name):#перевіряємо чи присутня ампула в файлі 1
    flag = False
    while not flag:
        for i in range(len(fileText1)):
            if fileText1[i].name == name:
                flag = True
        if flag == False:
            name = input("This ampule is not on the file 1 , pleace enter again :")
    return name


def getNumber1(fileText1, name, number):#отримаємо номер цих ліків в списку для подальшого діставання часу
    for i in range(len(fileText1)):
        if fileText1[i].name == name:
            number = i
    return number


def getTime(timeOp, timeAf):#отримання часу
    time = ""
    zero = "0"
    nextDay = "+1d "
    h = int(timeOp[0:2]) + int(timeAf[0:2])
    m = int(timeOp[3:5]) + int(timeAf[3:5])
    if m > 60:
        h = h + m // 60
        m = m % 60
    if h > 24:
        h -= 24                             #боротьба з костилями
        if h == 0 or h < 10:
            if m == 0 or m < 10:
                time = nextDay + zero + str(h) + ":" + zero + str(m)
            else:
                time = nextDay + zero + str(h) + ":" + str(m)
        elif m == 0 or m < 10:
            time = nextDay + str(h) + ":" + zero + str(m)
        else:
            time = nextDay + str(h) + ":" + str(m)
    elif m == 0 or m < 10:
        if h == 0 or h < 10:
            time = zero + str(h) + ":" + zero + str(m)
        else:
            time = str(h) + ":" + zero + str(m)
    elif h == 0 or h < 10:
        time = zero + str(h) + ":" + str(m)
    else:
        time = str(h) + ":" + str(m)
    return time


def outFile2(filename2, size):#виводимо вміст файлу 2
    print(filename2 + ":\n")
    ampoule = []
    with open(filename2, "rb") as file:
        for i in range(size):
            ampoule.append(pickle.load(file))
            line = ampoule[i].name1 + ", " + ampoule[i].timeOpening + ", " + ampoule[i].timeToUse + ";"
            print(line + "\n")
    file.close()


def removeAmpoule(filename2, filename3, size):# видаляємо вміст не дійсних ліків
    num = 0
    timeNow = input("Enter current time :")
    timeNow = verTimeAfeter(timeNow)
    fil = open(filename2, "rb")
    file = open(filename3, "wb")
    ampoule = []
    for i in range(size):
        ampoule.append(pickle.load(fil))
        time = ampoule[i].timeToUse
        if int(time[0:2]) > int(timeNow[0:2]) or time[0] == '+':
            pickle.dump(ampoule[i], file)
            num += 1
        elif int(time[0:2]) == int(timeNow[0:2]):
            if int(time[3:5]) > int(timeNow[3:5]):
                # pickle.dump(ampoule, file)
                pickle.dump(ampoule[i], file)
                num += 1

    fil.close()
    file.close()
    os.remove(filename2)
    os.rename(filename3, filename2)
    return num
