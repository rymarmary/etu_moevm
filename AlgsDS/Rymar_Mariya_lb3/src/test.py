import unittest
from main import *

def main_tester(data, other_data):
    n, m = map(int, data.split())
    time_array = list(map(int, other_data.split()))

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

    return result

class TestHeap(unittest.TestCase):

    def test1(self):
        self.assertEqual(main_tester("2 5", "1 2 3 4 5"), [(0, 0), (1, 0), (0, 1), (1, 2), (0, 4)])

    def test2(self):
        self.assertEqual(main_tester("2 0", ""), [])

    def test3(self):
        self.assertEqual(main_tester("3 1", "10"), [(0, 0)])