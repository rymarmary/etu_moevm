class Heap:
    def __init__(self):
        self.__size = 0
        self.__MAX_SIZE = 10 ** 5
        self.__heap = [None] * self.__MAX_SIZE


    def getParent(self, index):
        if index == 0:
            return 0
        return (index - 1) // 2

    def getRight(self, index):
        return 2 * index + 2

    def getLeft(self, index):
        return 2 * index + 1

    def insert(self, elem):
        if self.__size == self.__MAX_SIZE:
            return -1
        self.__heap[self.__size] = elem
        self.siftUp(self.__size)
        self.__size = self.__size + 1

    def siftUp(self, index):
        if index < 0 or index >= self.__MAX_SIZE:
            raise IndexError("Incorrect index")

        parent = self.getParent(index)
        while index > 0 and self.__heap[index] < self.__heap[parent]:
            self.__heap[parent], self.__heap[index] = self.__heap[index], self.__heap[parent]
            index = parent
            parent = self.getParent(index)

    def siftDown(self, index):
        if index < 0 or index >= self.__MAX_SIZE:
            raise IndexError("Incorrect index")

        left = self.getLeft(index)
        right = self.getRight(index)

        if left >= self.__size and right >= self.__size:
            return None

        if right >= self.__size:
            if self.__heap[left] < self.__heap[index]:
                minIndex = left
            else:
                minIndex = index

        else:
            if self.__heap[left] < self.__heap[right]:
                minIndex = left
            else:
                minIndex = right

            if self.__heap[minIndex] < self.__heap[index]:
                minIndex = minIndex
            else:
                minIndex = index

        if minIndex != index:
            self.__heap[minIndex], self.__heap[index] = self.__heap[index], self.__heap[minIndex]
            self.siftDown(minIndex)

    def extractMin(self):
        minElem = self.__heap[0]
        self.__heap[0], self.__heap[self.__size - 1] = self.__heap[self.__size - 1], None
        self.__size -= 1
        self.siftDown(0)
        return minElem


class Processor:
    def __init__(self, id, time=0):
        self.__id = id
        self.__time = time

    def time(self):
        return self.__time

    def id(self):
        return self.__id

    def increase(self, time):
        self.__time += time

    def __lt__(self, other):
        if self.time() == other.time():
            return self.id() < other.id()
        return self.time() < other.time()


def main():
    n, m = map(int, input().split())
    time_array = list(map(int, input().split()))

    heap = Heap()
    for i in range(n):
        heap.insert(Processor(i))

    result = list()
    for time in time_array:
        min_element = heap.extractMin()
        if min_element:
            result.append((min_element.id(), min_element.time()))
            min_element.increase(time)
            heap.insert(min_element)

    for i in result:
        print(*i)

if __name__ == '__main__':
    main()