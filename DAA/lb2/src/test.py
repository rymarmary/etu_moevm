import unittest
import greedyAlg
import aStar

tests = [[['a', 'g'],
          ['a', 'b', 3.0], ['a', 'c', 1.0], ['b', 'd', 2.0],
          ['b', 'e', 3.0], ['d', 'e', 4.0], ['e', 'a', 1.0],
          ['e', 'f', 2.0], ['a', 'g', 8.0], ['f', 'g', 1.0]],
         [['a', 'e'],
          ['a', 'b', 7.0], ['a', 'c', 3.0], ['b', 'c', 1.0],
          ['c', 'd', 8.0], ['b', 'e', 4.0]],
         [['a', 'd'],
          ['a', 'b', 1.0], ['b', 'c', 1.0], ['c', 'a', 1.0], ['a', 'd', 8.0]],
         [['a', 'b'],
          ['a', 'b', 1.0], ['a', 'c', 1.0]],
         [['b', 'e'],
          ['a', 'b', 1.0], ['a', 'c', 2.0], ['b', 'd', 7.0],
          ['b', 'e', 8.0], ['a', 'g', 2.0], ['b', 'g', 6.0],
          ['c', 'e', 4.0], ['d', 'e', 4.0], ['g', 'e', 1.0]]]

answers1 = [['abdefg'], ['abe'], ['ad'], ['ab'], ['bge']]

answers2 = [['ag'], ['abe'], ['ad'], ['ab'], ['be']]

class MyTestCase(unittest.TestCase):
    def test_greedy(self):
        for i in range(len(answers1)):
            self.assertEqual(greedyAlg.greedy(tests[i][1:], tests[i][0][0], tests[i][0][1]), *answers1[i])
    def test_astar(self):
        for i in range(len(answers2)):
            self.assertEqual(aStar.aStar(tests[i][1:], tests[i][0][0], tests[i][0][1]), *answers2[i])

if __name__ == '__main__':
    unittest.main()