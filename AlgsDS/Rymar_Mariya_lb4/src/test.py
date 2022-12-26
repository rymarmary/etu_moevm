import unittest
from main import hash

class TestHash(unittest.TestCase):

    def test1(self):
        pattern = [ord(s) - 65 for s in "aba"]
        text = [ord(s) - 65 for s in "abacaba"]
        self.assertEqual(hash(pattern, text), [0, 4])

    def test2(self):
        pattern = [ord(s) - 65 for s in "Test"]
        text = [ord(s) - 65 for s in "testTesttesT"]
        self.assertEqual(hash(pattern, text), [4])

    def test3(self):
        pattern = [ord(s) - 65 for s in "aaaaa"]
        text = [ord(s) - 65 for s in "baaaaaaa"]
        self.assertEqual(hash(pattern, text), [1, 2, 3])

    def test4(self):
        pattern = [ord(s) - 65 for s in "mnk"]
        text = [ord(s) - 65 for s in "12345"]
        self.assertEqual(hash(pattern, text), [])

    def test5(self):
        pattern = [ord(s) - 65 for s in "mnk"]
        text = [ord(s) - 65 for s in "mnk"]
        self.assertEqual(hash(pattern, text), [0])