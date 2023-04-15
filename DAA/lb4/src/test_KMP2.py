import unittest
import KMP2

class MyTestCase(unittest.TestCase):
    def test1(self):
        self.assertEqual(KMP2.KMP("word", "longword"), [-1])
    def test2(self):
        self.assertEqual(KMP2.KMP("word", "word"), [0])
    def test3(self):
        self.assertEqual(KMP2.KMP("word", "dwor"), [3])
    def test4(self):
        self.assertEqual(KMP2.KMP("word", "ordw"), [1])
    def test5(self):
        self.assertEqual(KMP2.KMP("word", "rodw"), [-1])

if __name__ == '__main__':
    unittest.main()
