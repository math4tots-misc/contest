#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef long long ll;

static ll pow10[15], pow3[15];

static ll eval(ll n, ll ops) {
  ll r = 0;
  while (n) {
    ll m = 0, op = 0, d = 0;
    while (n && op == 0) {
      op = ops % 3;
      m += (n % 10) * pow10[d];
      n /= 10;
      ops /= 3;
      d++;
    }
    if (op == 2) r -= m;
    else         r += m;
  }
  return r;
}

static ll ugly(ll n) {
  return n%2 == 0 || n%3 == 0 || n%5 == 0 || n%7 == 0;
}

static ll solve(const char * number) {
  ll d = strlen(number), l = pow3[d-1], ops, n = atoll(number), uglyc = 0;
  for (ops = 0; ops < l; ops++)
    if (ugly(eval(n, ops)))
      uglyc++;
  return uglyc;
}

static void prepare() {
  ll i;
  pow10[0] = pow3[0] = 1;
  for (i = 1; i < 15; i++)
    pow10[i] = 10 * pow10[i-1], pow3[i] = 3 * pow3[i-1];
}

int main(int argc, char** argv) {
  FILE * fin = fopen(argv[1], "r");
  prepare();
  char line[80];
  while (fgets(line, 80, fin)) {
    ll i = 0;
    while (isdigit(line[i]))
      i++;
    line[i] = '\0';
    printf("%lld\n", solve(line));
  }
}
