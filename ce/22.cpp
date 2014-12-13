#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

static unordered_map<int,int> memo;

int fib(int n) {
  if (memo.find(n) == memo.end()) memo[n] = fib(n-1) + fib(n-2);
  return memo[n];
}

int main(int argc, char** argv) {
  int n;
  ifstream fin(argv[1]);
  memo[0] = 0;
  memo[1] = 1;
  while (fin >> n) cout << fib(n) << endl;
  return 0;
}
