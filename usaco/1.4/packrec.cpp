/*
ID: kyjkim1
LANG: C++
TASK: packrec
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Rect {
	int w, h;
	Rect() {}
	Rect(int ww, int hh) : w(ww), h(hh) {}
	Rect rotate() { return Rect(h,w); }
	int area() {return w * h;}
	Rect canon() { return Rect(min(w,h),max(w,h)); }
	bool operator<(const Rect& r) const { return w < r.w || (w==r.w && h < r.h); }
	bool operator==(const Rect& r) const { return w == r.w && h == r.h; }
};

istream& operator>>(istream& in, Rect& r) {
	return in >> r.w >> r.h;
}

ostream& operator<<(ostream& out, Rect& r) {
	return out << r.w << ' ' << r.h;
}

static Rect pack(int type, Rect a, Rect b, Rect c, Rect d) {
	switch(type) {
	case 0:
		return Rect(
			a.w+b.w+c.w+d.w,
			max(max(a.h,b.h),max(c.h,d.h)));
	case 1:
		return Rect(
			max(a.w, b.w+c.w+d.w),
			a.h + max(b.h,max(c.h,d.h)));
	case 2:
		return Rect(
			a.w+max(b.w,c.w+d.w),
			max(a.h,b.h+max(c.h,d.h)));
	case 3:
		return Rect(
			a.w+max(b.w,c.w)+d.w,
			max(b.h+c.h,max(a.h,d.h)));
	case 4:
		return Rect(
			max(a.w,b.w)+c.w+d.w,
			max(a.h+b.h,max(c.h,d.h)));
	case 5:
		return (a.h >= b.h && c.w >= a.w) ?
			Rect(
				max(a.w+b.w,c.w+d.w),
				max(a.h+c.h,d.h+b.h)) : pack(0,a,b,c,d);
	}
	return Rect(0,0);
}

int main() {
	ifstream fin("packrec.in");
	ofstream fout("packrec.out");
	vector<Rect> rs(4);
	fin >> rs[0] >> rs[1] >> rs[2] >> rs[3];
	sort(rs.begin(),rs.end());
	int best = 1 << 30;
	set<Rect> br;
	do {
		for (int f = 0; f < 16; f++) {
			for (int t = 0; t < 6; t++) {
				Rect r = pack(t,
					(f >> 0)%2 ? rs[0] : rs[0].rotate(),
					(f >> 1)%2 ? rs[1] : rs[1].rotate(),
					(f >> 2)%2 ? rs[2] : rs[2].rotate(),
					(f >> 3)%2 ? rs[3] : rs[3].rotate());
				if (r.area() <= best) {
					if (r.area() < best) {
						best = r.area();
						br.clear();
					}
					br.insert(r.canon());
				}
			}
		}
	} while (next_permutation(rs.begin(),rs.end()));
	fout << best << endl;
	for (set<Rect>::iterator it = br.begin(); it != br.end(); it++) {
		fout << it->w << ' ' << it->h << endl;
	}
}