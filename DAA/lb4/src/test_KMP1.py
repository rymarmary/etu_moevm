import unittest
import KMP1

class MyTestCase(unittest.TestCase):
    def test1(self):
        self.assertEqual(KMP1.KMP("abc", "asdffghjkl"), ["-1"])
    def test2(self):
        self.assertEqual(KMP1.KMP("abc", "abcabcabcabc"), ['0', '3', '6', '9'])
    def test3(self):
        self.assertEqual(KMP1.KMP("longword", "longword"), ['0'])
    def test4(self):
        self.assertEqual(KMP1.KMP("word", "wo"), ["-1"])
    def test5(self):
        self.assertEqual(KMP1.KMP("pattern", "rrrpatternlllll"), ['3'])

if __name__ == '__main__':
    unittest.main()
