/*
Hopefully, this one runs fast enough ....

Results turned out about the same as the original  Python version ...
*/

#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;
#define MAX_N 1000000

typedef unsigned long long llu;

static llu N, K;
static char S[MAX_N + 1], X[MAX_N], XO[MAX_N], Y[MAX_N], YO[MAX_N];
static unordered_map<llu, char> MEMO;

static inline char encode(char c) {
  switch(c) {
  case 'A': return 0;
  case 'B': return 3;
  case 'C': return 1;
  case 'D': return 2;
  }
  return 0;
}

static inline char decode(char x) {
  switch(x) {
  case 0: return 'A';
  case 1: return 'C';
  case 2: return 'D';
  case 3: return 'B';
  }
  return 0;
}

static llu dd(llu t) {
  llu dx = (llu) ceil(log((double) t) / log((double) 2));
  llu dt = ((llu) 1) << dx;
  if (dt > t)
    dt >>= 1;
  return dt;
}

static char f(char * X, llu x, llu t) {
  
  x %= N;
  
  // printf("%llu %llu\n", x, t);
  
  llu key = (t << 32) + x;
  
  if (MEMO.find(key) == MEMO.end()) {
    if (t == 0)
      MEMO[key] = X[x];
    else {
      llu dt = dd(t);
      MEMO[key] = f(X, x, t - dt) ^ f(X, x + dt, t - dt);
    }
  }
  
  return MEMO[key];
}

static inline void solve1(char * X, char * XO) {
  MEMO.clear();
  for (llu i = 0; i < N; i++)
    XO[i] = f(X, i, K);
}

int main() {
  scanf("%llu %llu %s", &N, &K, S);
  
  for (int i = 0; i < N; i++) {
    X[i] = encode(S[i]) & 1;
    Y[i] = encode(S[i]) & 2;
  }
  
  solve1(X, XO);
  solve1(Y, YO);
  
  for (int i = 0; i < N; i++) {
    printf("%c", decode(XO[i] ^ YO[i]));
  }
  printf("\n");
}
