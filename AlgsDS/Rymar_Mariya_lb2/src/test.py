import unittest
from src import func_merge

class TestMergeSort(unittest.TestCase):

    def test1(self):
        self.assertEqual(func_merge([(0, 1)], list()), [(0, 1)])

    def test2(self):
        self.assertEqual(func_merge([(0, 0)], list()), [(0, 0)])

    def test3(self):
        self.assertEqual(func_merge([(0, 32), (1, 11), (2, 3)], list()), [(2, 3), (1, 11), (0, 32)])

    def test4(self):
        self.assertEqual(func_merge([(0, 5), (1, 1)], list()), [(1, 1), (0, 5)])

    def test5(self):
        self.assertEqual(func_merge([(0, 5), (1, 6), (2, -4), (3, 12)], list()), [(2, -4), (0, 5), (1, 6), (3, 12)])
