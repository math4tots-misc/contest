// g++ lazy_sort.cpp --std=c++11 -Wl,-stack_size -Wl,10000000
#include <cassert>
#include <string>
#include <iostream>
#include <deque>
using namespace std;

const int FRONT = 0;
const int BACK = 1;

int get(deque<int>& xs, int dir) {
  if (dir == FRONT)
    return xs.front();
  else
    return xs.back();
}

void push(deque<int>& xs, int dir, int x) {
  if (dir == FRONT)
    xs.push_front(x);
  else
    xs.push_back(x);
}

int pop(deque<int>& xs, int dir) {
  if (dir == FRONT) {
    int ret = xs.front();
    xs.pop_front();
    return ret;
  } else {
    int ret = xs.back();
    xs.pop_back();
    return ret;
  }
}

bool valid(deque<int>& from, int fdir, deque<int>& to, int tdir) {
  if (tdir == FRONT)
    return get(from, fdir) + 1 == get(to, tdir);
  else
    return get(to, tdir) + 1 == get(from, fdir);
}

struct Insert {
  deque<int>& from; int fdir; deque<int>& to; int tdir;
  Insert(deque<int>& from, int fdir, deque<int>& to, int tdir) :
      from(from), fdir(fdir), to(to), tdir(tdir) {
    push(to, tdir, pop(from, fdir));
  }
  ~Insert() {
    push(from, fdir, pop(to, tdir));
  }
};

bool solve(deque<int>& from, deque<int>& to) {
  if (from.size() == 0) {
    return true;
  } else if (to.size() == 0) {
    for (int dir = FRONT; dir <= BACK; dir++) {
      Insert i(from, dir, to, FRONT);
      if (solve(from, to))
        return true;
    }
  } else {
    for (int fdir = FRONT; fdir <= BACK; fdir++) {
      for (int tdir = FRONT; tdir <= BACK; tdir++) {
        if (valid(from, fdir, to, tdir)) {
          Insert i(from, fdir, to, tdir);
          if (solve(from, to))
            return true;
        }
      }
    }
  }

  return false;
}

bool solve(deque<int> from) {
  deque<int> to;
  return solve(from, to);
}

int main() {
  assert(solve(deque<int>({1, 2, 3, 4})));
  assert(!solve(deque<int>({1, 3, 2, 4})));
  assert(!solve(deque<int>({2, 4, 3, 1, 5, 9, 6, 7, 8})));
  assert(solve(deque<int>({4, 3, 2, 1, 6, 5})));
  assert(solve(deque<int>({3, 4, 5, 1, 2})));
  {
    deque<int> from;
    for (int i = 1; i <= 50000; i++) {
      from.push_back(i);
    }
    assert(solve(from));
  }

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    deque<int> from;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      from.push_back(x);
    }
    string answer = solve(move(from)) ? "yes" : "no";
    cout << "Case #" << t << ": " << answer << endl;
  }
}
