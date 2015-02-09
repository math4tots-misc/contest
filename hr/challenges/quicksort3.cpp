// Sample will pass but only first two tests seem to pass.
#include <iostream>
#include <vector>
using namespace std;

vector<int> n;

void print() {
  for (int i = 0; i < n.size(); i++)
    cout << n[i] << ' ';
  cout << endl;
}

template <class Iterator>
bool sorted(Iterator a, Iterator b) {
  for (Iterator i = a+1; i != b; i++)
    if (*(i-1) > *i)
      return false;
  return true;
}

template <class Iterator>
Iterator partition(Iterator a, Iterator b) {
  b--;
  while (*a < *b)
    a++;
  for (Iterator i = a; i != b; i++)
    if (*i < *b && i != a)
      swap(*a++, *i);
  if (a != b)
    swap(*a, *b);
  return a;
}

template <class Iterator>
void sort(Iterator a, Iterator b) {
  if (a == b || sorted(a, b))
    return;
  Iterator i = partition(a, b);
  print();
  sort(a, i);
  sort(i, b);
}

int main() {
  int N;
  cin >> N;
  n.resize(N);
  for (int i = 0; i < N; i++)
    cin >> n[i];
  sort(n.begin(), n.end());
}
