#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
string tostring(T t) {
	stringstream ss;
	ss << t;
	return ss.str();
}

int main() {
	cout << tostr(12) << endl;
}
