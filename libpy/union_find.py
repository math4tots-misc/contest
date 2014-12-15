class UnionFind(object):
  """Textbook UnionFind implementation.
  This UnionFind implementation keeps a forest of keys and keeps track of the
    sizes of each tree.
  """

  def __init__(self):
    self._key_table = dict()
    self._size_table = dict()

  def insert(self, key):
    """Initializes the key if this UnionFind instance has not encountered this
        key before."""
    if key not in self._key_table:
      self._key_table[key] = key
      self._size_table[key] = 1

  def find(self, key):
    """Finds the root of the tree that contains the given key."""
    self.insert(key)
    original_key = key
    keys = [key]
    while self._key_table[key] != key:
      keys.append(key)
      key = self._key_table[key]
    root = self._key_table[key]
    for key in keys:
      self._key_table[key] = root
    return self._key_table[original_key]

  def union(self, a, b):
    """Unifies the trees that contain keys a and b.
    Does nothing if a and b belong to the same tree.
    Attaches the root of the smaller tree to the bigger one.
    If both trees have the same size, the tree specified by b points to the
      tree specified by a.
    """
    self.insert(a)
    self.insert(b)
    a = self.find(a)
    b = self.find(b)
    if a != b:
      if self._size_table[a] < self._size_table[b]:
        a, b = b, a
      self._key_table[b] = a
      self._size_table[a] += self._size_table[b]
      del self._size_table[b]

  @property
  def size(self):
    """Returns the toal number of keys in this UnionFind forest."""
    return len(self._key_table)

  def sizeof(self, key):
    """Returns the size of the tree that contains the given key."""
    return self._size_table[self.find(key)]

  @property
  def keys(self):
    """Returns an iterable of all keys in the forest."""
    return iter(self._key_table)

  @property
  def roots(self):
    """Returns an iterable of the roots of each tree in the forest."""
    return iter(self._size_table)
