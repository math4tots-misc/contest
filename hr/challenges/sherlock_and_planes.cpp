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

template <class T, class Sieve=vector<bool> >
Sieve prime_sieve(T N) {
  Sieve sieve(N+1, true);
  sieve[0] = sieve[1] = false;
  for (T i = 2; i <= N; i++)
    if (sieve[i])
      for (T j = i+i; j < N; j += i)
        sieve[j] = false;
  return sieve;
}

template <class T, class Primes=vector<T>, class Sieve=vector<bool> >
Primes primes_up_to(T N) {
  Sieve sieve(prime_sieve<T, Sieve>(N));
  Primes primes;
  for (T i = 2; i <= N; i++)
    if (sieve[i])
      primes.push_back(i);
  return primes;
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

  Scalar& operator[](size_t i) {
    return _buffer[i];
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

  Point& operator+=(const Point& p) {
    for (size_t i = 0; i < Dimension; i++)
      _buffer[i] += p._buffer[i];
    return *this;
  }

  Point& operator-=(const Point& p) {
    for (size_t i = 0; i < Dimension; i++)
      _buffer[i] -= p._buffer[i];
    return *this;
  }

  Point& operator*=(const Scalar& s) {
    for (size_t i = 0; i < Dimension; i++)
      _buffer[i] *= s;
    return *this;
  }

  Point operator+(const Point& p) const {
    Point r(*this);
    r += p;
    return r;
  }

  Point operator-(const Point& p) const {
    Point r(*this);
    r -= p;
    return r;
  }

  Point operator*(const Scalar& s) const {
    Point r(*this);
    r *= s;
    return r;
  }

  Scalar dot(const Point& p) const {
    Scalar ret = 0;
    for (size_t i = 0; i < Dimension; i++)
      ret += _buffer[i] * p._buffer[i];
    return ret;
  }

  /* -- Only really works for Dimension == 3 -- */
  Point cross(const Point& p) const {
    return Point({{
        _buffer[1] * p._buffer[2] - _buffer[2] * p._buffer[1],
        _buffer[2] * p._buffer[0] - _buffer[0] * p._buffer[2],
        _buffer[0] * p._buffer[1] - _buffer[1] * p._buffer[0]}});
  }
};

template <size_t D, class S>
Point<D, S> operator*(const S& s, const Point<D, S>& p) {
  return p * s;
}

template <size_t I, size_t Dimension, class Scalar>
Scalar& get(Point<Dimension, Scalar>& p) {
  return p._buffer[I];
}

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

/*** HyperPlane */
template <class Point>
struct HyperPlane {
  Point _normal, _translation;

  HyperPlane(Point n=Point(), Point t=Point()) : _normal(n), _translation(t) {}

  bool contains(const Point& p) const {
    return _normal.dot(p - _translation) == 0;
  }
};

template <class Point=Point<3> >
struct Plane : HyperPlane<Point> {
  using HyperPlane<Point>::HyperPlane;

  static Plane fromPoints(Point a, Point b, Point c) {
    return Plane((b-a).cross(c-a), a);
  }

};

template <class Point=Point<2> >
struct Line : HyperPlane<Point> {
  using HyperPlane<Point>::HyperPlane;

  static Line fromPoints(Point a, Point b) {
    Point m = a - b;
    return Line(Point({{m[1], -m[0]}}), a);
  }
};

template <class Point>
ostream& operator<<(ostream& out, const Plane<Point>& plane) {
  return out << "Plane(" << plane._normal << ", " << plane._translation << ')';
}

template <class Point>
string to_string(const Plane<Point>& plane) {
  ostringstream ss;
  ss << plane;
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

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    Point<3> p[4];
    for (int i = 0; i < 4; i++)
      cin >> p[i][0] >> p[i][1] >> p[i][2];
    cout << (Plane<>::fromPoints(p[0], p[1], p[2]).contains(p[3]) ? "YES" : "NO") << endl;
  }
}