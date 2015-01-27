#include "utils.hpp"

int main() {

	/** print stl containers */
	assert(to_string(pair<string,int>("hi", 5)) == "pair(hi, 5)");
  assert(to_string(vector<int>({1, 2, 3})) == "vector(1, 2, 3)");
  assert(to_string(deque<int>({1, 2, 3})) == "deque(1, 2, 3)");
	assert(to_string(set<int>({1, 2, 3})) == "set(1, 2, 3)");
	assert(to_string(map<int,int>({{1, 2}})) == "map(pair(1, 2))");
	assert(to_string(array<int, 2>({{5, 5}})) == "array(5, 5)");
	assert(to_string(tuple<char,int>('a', 5)) == "tuple(a, 5)");

	/** gcd */
	assert(gcd(0, 4) == 4);
	assert(gcd(5, 0) == 5);
	assert(gcd(6, 9) == 3);

  /** primes */
	assert(primes_up_to(11) == vector<int>({2, 3, 5, 7, 11}));

	/** PriorityQueue */
	{
		PriorityQueue<char, int> queue;
		queue.update('a', 10);
		queue.update('b', 0);
		queue.update('a', 5);
		assert(queue.size() == 2);
		assert(queue.pop() == 'b');
		assert(queue.size() == 1);
		assert(queue.priority_of('a') == 5);
	}

	assert(
			to_string(PriorityQueue<char, int>({{'a', 5}})) ==
			"PriorityQueue(tuple(5, a))");

	/** Point */
	assert((Point<>({{5, 5}}) == Point<>({{5, 5}})));
	assert((Point<>({{5, 10}}) < Point<>({{10, 5}})));
	{
		Point<3> point({{1, 2, 3}});
		assert(point[0] == 1);
		assert(get<2>(point) == 3);
	}
	assert(to_string(Point<>()) == "Point(0, 0)");
	assert(to_string(Point<>{{3.5, 3}}) == "Point(3.5, 3)");
	assert(to_string(Point<>{{3.5, 4}} + Point<>{{3.5, 4}}) == "Point(7, 8)");
	assert(to_string(Point<>{{3.5, 4}} - Point<>{{3.5, 4}}) == "Point(0, 0)");
	assert(to_string(2.0 * Point<>{{3.5, 4.5}}) == "Point(7, 9)");
	assert(Point<>({{2, 4}}).dot(Point<>({{4, 2}})) == 16);
	assert(
			Point<3>({{1, 0, 0}}).cross(Point<3>({{0, 1, 0}})) ==
			Point<3>({{0, 0, 1}}));

	/** Plane */
	{
		Plane<> plane(Point<3>({{0, 0, 1}}));
		assert(plane.contains(Point<3>({{0, 1, 0}})));
		assert(plane.contains(Point<3>({{1, 0, 0}})));
		assert(!plane.contains(Point<3>({{0, 0, 1}})));
		assert(to_string(plane) == "Plane(Point(0, 0, 1), Point(0, 0, 0))");
	}
	{
		Plane<> plane(Plane<>::fromPoints3D(
				Point<3>({{1, 0, 0}}),
				Point<3>({{0, 1, 0}}),
				Point<3>({{1, 1, 0}})));
		assert(plane.contains(Point<3>({{2, 5.5, 0}})));
		assert(!plane.contains(Point<3>({{2, 2, 1}})));
	}
}
