from main import treeHeight
import unittest

class TestTreeHeight(unittest.TestCase):

    def test1(self):
        self.assertEqual(treeHeight([4, -1, 4, 1, 1], 5), 3)

    def test2(self):
        self.assertEqual(treeHeight([-1, 0, 4, 0, 3], 5), 4)

    def test3(self):
        self.assertEqual(treeHeight([2, 2, -1, 0, 2], 4), 3)

    def test4(self):
        self.assertEqual(treeHeight([1, 2, 3, -1, 3, 6, 3], 6), 4)

    def test5(self):
        self.assertRaises(ValueError, treeHeight, [], 0)
