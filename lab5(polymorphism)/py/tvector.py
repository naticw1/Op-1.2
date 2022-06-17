from abc import ABC, abstractmethod

class TVector(ABC):

    def __init__(self, x):
        self.x = x

    def out(self):
        print(f"X ={self.x}", end='')

    @abstractmethod
    def isParal(self, vector):
        pass

    @abstractmethod
    def isPerpen(self, vector):
        pass

    @abstractmethod
    def vectorLen(self):
        pass