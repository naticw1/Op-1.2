from tvector import TVector
from math import sqrt


class TVectorR2(TVector):
    def __init__(self, x, y):
        super().__init__(x)
        self.__y = y

    def out(self):
        super().out()
        print(f" Y ={self.__y}\n", end = '')

    def isParal(self, vector):
        tmp = self.x * vector.__y - self.__y * vector.x
        if tmp == 0:
            return True
        return False

    def isPerpen(self, vector):
        tmp = self.x * vector.x + self.__y * vector.__y
        if tmp == 0:
            return True
        return False

    def vectorLen(self):
        return sqrt(self.x ** 2 + self.__y ** 2)