from random import randint
import unittest
import cons


class ConsTest(unittest.TestCase):

    def test_simple(self):
        a=3
        b=4
        self.assertEqual(cons.car(cons.cons(a, b)), 3)
        self.assertEqual(cons.cdr(cons.cons(a, b)), 4)
        
    def test_random_numbers(self):
        a=randint(1, 1000)
        b=randint(1001, 2000)
        self.assertEqual(cons.car(cons.cons(a, b)), a)
        self.assertEqual(cons.cdr(cons.cons(a, b)), b)
 
if __name__ == '__main__':
    unittest.main()
