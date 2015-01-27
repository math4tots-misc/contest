/**
 * Some utilities for programming contests.
 * Requires C++11.
 */
#include <cassert>

#include <algorithm>

#include <regex>

#include <utility>

#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>

#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <tuple>
#include <queue>

using namespace std;

/*** print stl containers */

/** forward references */
template <class Container>
ostream& dump_container(ostream& out, Container container);

template <class Tuple, size_t I=tuple_size<Tuple>::value>
struct dump_tuple;

/** pair */
template <class First, class Second>
ostream& operator<<(ostream& out, pair<First, Second> p) {
  return out << "pair(" << get<0>(p) << ", " << get<1>(p) << ')';
}

template <class First, class Second>
string to_string(pair<First, Second> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}

/** vector */
template <class T>
ostream& operator<<(ostream& out, vector<T> m) {
  return dump_container(out << "vector", m);
}

template <class T>
string to_string(vector<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}

/** deque */
template <class T>
ostream& operator<<(ostream& out, deque<T> m) {
  return dump_container(out << "deque", m);
}

template <class T>
string to_string(deque<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}

/** set */
template <class T>
ostream& operator<<(ostream& out, set<T> m) {
  return dump_container(out << "set", m);
}

template <class T>
string to_string(set<T> c) {
  ostringstream ss;
  ss << c;
  return ss.str();
}

/** map */
template <class Key, class Value>
ostream& operator<<(ostream& out, map<Key, Value> m) {
  return dump_container(out << "map", m);
}

template <class Key, class Value>
string to_string(map<Key, Value> c) {
  ostringstream ss;
  ss << c;
  return ss.str();
}

/** array */
template <class T, size_t N>
ostream& operator<<(ostream& out, array<T, N> m) {
  return dump_container(out << "array", m);
}

template <class T, size_t N>
string to_string(array<T, N> c) {
  ostringstream ss;
  ss << c;
  return ss.str();
}

/** tuple */
template <class... Args>
ostream& operator<<(ostream& out, tuple<Args...> t) {
  return dump_tuple<decltype(t)>::call(out << "tuple(", t) << ')';
}

template <class... Args>
string to_string(tuple<Args...> c) {
  ostringstream ss;
  ss << c;
  return ss.str();
}

/*** number theory */

template <class T>
T gcd(T a, T b) {
  while (b != 0) {
    T c = a % b;
    a = b;
    b = c;
  }
  return a;
}

template <class T>
vector<bool> prime_sieve(T N) {
  vector<bool> sieve(N+1, true);
  sieve[0] = sieve[1] = false;
  for (T i = 2; i <= N; i++)
    if (sieve[i])
      for (T j = i+i; j < N; j += i)
        sieve[j] = false;
  return move(sieve);
}

template <class T>
vector<T> primes_up_to(T N) {
  vector<bool> sieve(prime_sieve(N));
  vector<T> primes;
  for (T i = 2; i <= N; i++)
    if (sieve[i])
      primes.push_back(i);
  return move(primes);
}

/*** PriorityQueue */
template <class Item, class Priority>
struct PriorityQueue {
  typedef tuple<Priority, Item> Pair;
  typedef typename set<Pair>::iterator iterator;
  map<Item, Priority> _priorities;
  set<Pair> _pairs;

  PriorityQueue() {}

  PriorityQueue(initializer_list<pair<Item, Priority> > args) {
    for (auto p : args) {
      update(p.first, p.second);
    }
  }

  size_t size() const {
    return _pairs.size();
  }

  void update(Item item, Priority priority) {
    if (_priorities.find(item) != _priorities.end())
      _pairs.erase(Pair(_priorities[item], item));
    _pairs.insert(Pair(priority, item));
    _priorities[item] = priority;
  }

  Item& peek() {
    return *_pairs.begin();
  }

  Priority priority_of(Item item) {
    return _priorities[item];
  }

  Item pop() {
    Pair pair(*_pairs.begin());
    _pairs.erase(pair);
    _priorities.erase(get<1>(pair));
    return get<1>(pair);
  }

  iterator begin() {
    return _pairs.begin();
  }

  iterator end() {
    return _pairs.end();
  }
};

template <class Key, class Value>
ostream& operator<<(ostream& out, PriorityQueue<Key, Value> m) {
  return dump_container(out << "PriorityQueue", m);
}

template <class Key, class Value>
string to_string(PriorityQueue<Key, Value> c) {
  ostringstream ss;
  ss << c;
  return ss.str();
}

/*** Point */
/* I seem to be essentially reimplementing <array>.
 * But I feel like <array> didn't have that much to begin with anyway.
 */
template <size_t Dimension=2, class Scalar=double>
struct Point {

  Scalar _buffer[Dimension];

  Scalar * begin() {
    return _buffer;
  }

  Scalar * end() {
    return _buffer + Dimension;
  }

  const Scalar * cbegin() const {
    return _buffer;
  }

  const Scalar * cend() const {
    return _buffer + Dimension;
  }

  size_t size() const {
    return Dimension;
  }

  bool operator==(const Point& p) const {
    return equal(cbegin(), cend(), p.cbegin());
  }

  bool operator<(const Point& p) const {
    return lexicographical_compare(cbegin(), cend(), p.cbegin(), p.cend());
  }
};

template <size_t Dimension, class Scalar>
ostream& operator<<(ostream& out, const Point<Dimension, Scalar>& p) {
  return dump_container(out << "Point", p);
}

template <size_t Dimension, class Scalar>
string to_string(const Point<Dimension, Scalar>& p) {
  ostringstream ss;
  ss << p;
  return ss.str();
}


/*** dump_* implementations have to come at the end */

/** dump_container */
template <class Container>
ostream& dump_container(ostream& out, Container container) {
  out << '(';
  if (container.size()) {
    auto p = container.begin();
    out << *p;
    p++;
    for (; p != container.end(); p++)
      out << ", " << *p;
  }
  return out << ')';
}

/** dump_tuple */
template <class Tuple, size_t I>
struct dump_tuple {
  static ostream& call(ostream& out, Tuple t) {
    return dump_tuple<Tuple, I-1>::call(out, t) << ", " << get<I-1>(t);
  }
};

template <class Tuple>
struct dump_tuple<Tuple, 0>{
  static ostream& call(ostream& out, Tuple t) {
    return out;
  }
};

template <class Tuple>
struct dump_tuple<Tuple, 1>{
  static ostream& call(ostream& out, Tuple t) {
    return out << get<0>(t);
  }
};
