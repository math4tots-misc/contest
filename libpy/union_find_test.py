import unittest
from .union_find import UnionFind

class SimpleTestCase(unittest.TestCase):

  def setUp(self):
    self.uf = UnionFind()
    for i in range(1, 10):
      self.uf.union(i-1, i)
    for i in range(11, 20):
      self.uf.union(i-1, i)
    self.uf.insert(20)

  def test_sizeof(self):
    self.assertEqual(10, self.uf.sizeof(0))
    self.assertEqual(10, self.uf.sizeof(10))
    self.assertEqual(1,  self.uf.sizeof(20))

  def test_size(self):
    self.assertEqual(21, self.uf.size)

  def test_keys(self):
    self.assertEqual(set(self.uf.keys), set(range(21)))

  def test_roots(self):
    self.assertEqual(set(self.uf.roots), set([0, 10, 20]))

if __name__ == '__main__':
  unittest.main()
