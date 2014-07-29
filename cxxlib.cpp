#include <iostream>
#include <string>
#include <vector>

template <class T> struct Pointer {
	T * ptr;
	Pointer(T * p) : ptr(p) { p->own(); }
	Pointer(const Pointer& p) : ptr(p.ptr) { ptr->own(); }
	Pointer& operator=(const Pointer& p) {T * oldptr = ptr;ptr = p.ptr;ptr->own();oldptr->unown(); return *this; }
	T * operator->() const { return ptr; }
	
	
	
	~Pointer() { ptr->unown(); }
};

template <class T> struct Object {
	T object;
	long references;
	
	Object(const T& t) : object(t), references(0) {}
	virtual ~Object() {}
	
	void own() { references++; }
	void unown() { references--; if (references == 0) delete this; std::cout << "object deleted\n"; }
	
	
};

struct String : public Object<std::string> {
	String(const std::string& t) : Object(t) {}
};

template <class T> struct Vector : public Object<std::vector<T> > {
	Vector(const std::vector<T>& t) : Object<std::vector<T> >(t) {}
};

using namespace std;
Pointer<Vector<Pointer<String> > > not_main() {
	Pointer<String> p(new String(std::string("Hello!")));
	Pointer<Vector<int> > q(new Vector<int>(std::vector<int>()));
	Pointer<Vector<Pointer<String> > > r(new Vector<Pointer<String> >(std::vector<Pointer<String> >()));
	q->object.push_back(13);
	r->object.push_back(p);
	cout << p->object << endl;
	return r;
}

int main() {
	Pointer<Vector<Pointer<String> > > p = not_main();
	cout << p->object.back()->object << endl;
}