#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct BigInt {
	typedef string::const_reverse_iterator I;
	const string x;
	
	BigInt(string s) : x(s) {}
	BigInt(const char * s) : x(s) {}
	
	bool operator<(const BigInt& y) const {
		if (x[0] == '-')
			if (y.x[0] == '-')  return y.x < x;
			else                return true;
		else if (y.x[0] == '-') return false;
		return x < y.x;
	}
	
	BigInt operator-() const {
		return (x[0] == '-') ? x.substr(1) : (string("-") + x);
	}
	
	BigInt operator+(const BigInt& y) const {
		if (x[0] == '-')
			if (y.x[0] == '-')   return -(BigInt(x.substr(1)) + BigInt(y.x.substr(1)));
			else                 return BigInt(x.substr(1)) - y;
		else if (y.x[0] == '-')  return (*this) - BigInt(y.x.substr(1));
		
		string c;
		I ia = x.rbegin(), ib = y.x.rbegin();
		int carry = 0;
		
		for (;ia != x.rend() && ib != y.x.rend(); ia++, ib++) {
			int a = *ia - '0', b = *ib - '0';
			int v = carry + a + b;
			carry = v / 10;
			c.push_back('0' + (v%10));
		}
		
		for (;ia != x.rend(); ia++)
			c.push_back(*ia);
		
		for (;ib != y.x.rend(); ib++)
			c.push_back(*ib);
		
		reverse(c.begin(),c.end());
		
		return c;
	}
	
	BigInt operator-(const BigInt& y) const {
		
		return "0";
	}
};

ostream& operator<<(ostream& out, const BigInt& b) {
	return out << b.x;
}

int main() {
	BigInt a("13234"), b("44");
	vector<BigInt> v;
	cout << a << ' ' << b << endl;
	cout << a + b << endl;
}

