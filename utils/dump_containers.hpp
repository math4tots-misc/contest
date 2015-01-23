/**
 * Helpers for print_stl_containers.hpp that has to come
 * after all containers.
 */

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
