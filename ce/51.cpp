#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point operator-(const Point p) const { return Point(x-p.x, y-p.y); }
  bool operator<(const Point p) const { return norm() < p.norm(); }
  double norm() const { return sqrt(pow(x, 2) + pow(y, 2)); }
};

static bool solve_next(FILE * fin) {
  long N;
  double best = 10000;
  std::vector<Point> pts;
  fscanf(fin, "%ld", &N);
  if (N == 0) return false;
  for (long i = 0; i < N; i++) {
    double x, y;
    fscanf(fin, "%lf %lf", &x, &y);
    pts.push_back(Point(x, y));
  }
  std::sort(pts.begin(), pts.end());
  for (long ia = 0; ia < N; ia++) {
    Point a(pts[ia]);
    for (long ib = ia+1; ib < N; ib++) {
      Point b(pts[ib]);
      if (b.norm() - a.norm() > best) break;
      best = std::min(best, (a-b).norm());
    }
  }
  if (best == 10000) printf("INFINITY\n");
  else               printf("%.4lf\n", best);
  return true;
}

int main(int argc, char** argv) {
  FILE * fin = fopen(argv[1], "r");
  while (solve_next(fin));
}
