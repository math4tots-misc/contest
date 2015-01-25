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
