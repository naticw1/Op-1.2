from tvector import TVector
from math import sqrt
class TVectorR3(TVector):
    def __init__(self, x, y, z):
        super().__init__(x)
        self.__y = y
        self.__z = z

    def out(self):
        super().out()
        print(f" Y ={self.__y} Z = {self.__z}\n", end = '')

    def isParal(self, vector):
        tmp = (self.__y * vector.__z - vector.__y * self.__z) - (self.x * vector.__z - vector.x * self.__z) + (self.x * vector.__y - vector.x * self.__y)
        if tmp == 0:
            return True
        return False

    def isPerpen(self, vector):
        tmp = self.x * vector.x + self.__y * vector.__y + self.__z * vector.__z
        if tmp == 0:
            return True
        return False

    def vectorLen(self):
        return sqrt(self.x ** 2 + self.__y ** 2 + self.__z ** 2)