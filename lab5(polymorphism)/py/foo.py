from tvector2R import TVectorR2
from tvectorR3 import TVectorR3


def create_arr(n, m):
    arr = []
    print("Enter vector R^2 :")
    for i in range(0, n):
        print(f"Enter {i+1} vector coordinates:")
        print(" ")
        x = valNumber("Enter X :")
        y = valNumber("Enter Y :")
        arr.append(TVectorR2(x, y))
    print("Enter vector R^3 :")
    for i in range(0, m):
        print(f"Enter {i + 1} vector coordinates:")
        print(" ")
        x = valNumber("Enter X :")
        y = valNumber("Enter Y :")
        z = valNumber("Enter Z :")
        arr.append(TVectorR3(x, y, z))
    return arr


def valNumber(text):
    isValid = False
    while not isValid:
        try:
            number = float(input(text))
        except ValueError:
            print("Enter correct number :")
        else:
            isValid = True
    return number


def sum_of_Paralel(arr, n):
    par = []
    sum = 0
    for i in range(1, n):
        if arr[0].isParal(arr[i]):
            sum += arr[i].vectorLen()
            par.append(arr[i])
    return sum, par


def sum_of_Perpen(arr, n, m):
    per = []
    sum = 0
    for i in range(n + 1, n + m):
        if arr[n].isPerpen(arr[i]):
            per.append(arr[i])
            sum += arr[i].vectorLen()
    return sum, per


def out_vectors(arr, n, m):
    print("Vectors R^2")
    for i in range(0, n):
        arr[i].out()
    print("Vectors R^3 :")
    for i in range(n, m + n):
        arr[i].out()


def out_to_zero(arr, text):
    print(text)
    for i in range(0, len(arr)):
        arr[i].out()
