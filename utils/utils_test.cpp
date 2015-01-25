#include "utils.hpp"

int main() {
	/** read_all.hpp */
	{
		ifstream fin("read_all.hpp");
		assert(
				read_all(fin) ==
				"inline string read_all(istream& t) {\n"
				"\treturn string((istreambuf_iterator<char>(t)), "
				"istreambuf_iterator<char>());\n"
				"}\n");
	}

	/** print_stl_containers.hpp */
	assert(to_string(pair<string,int>("hi", 5)) == "pair(hi, 5)");
  assert(to_string(vector<int>({1, 2, 3})) == "vector(1, 2, 3)");
  assert(to_string(deque<int>({1, 2, 3})) == "deque(1, 2, 3)");
	assert(to_string(set<int>({1, 2, 3})) == "set(1, 2, 3)");
	assert(to_string(map<int,int>({{1, 2}})) == "map(pair(1, 2))");
	assert(to_string(tuple<char,int>('a', 5)) == "tuple(a, 5)");

	/** gcd.hpp */
	assert(gcd(0, 4) == 4);
	assert(gcd(5, 0) == 5);
	assert(gcd(6, 9) == 3);

  /** primes.hpp */
	assert(primes_up_to(11) == vector<int>({2, 3, 5, 7, 11}));

	/** priority_queue.hpp */
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
}
