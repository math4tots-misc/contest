/**
 * Problem with builtin priority_queue is that it doesn't
 * have update priority.
 */
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
