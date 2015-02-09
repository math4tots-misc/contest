#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int dx[] = { 1, -1,  0,  0};
  int dy[] = { 0,  0,  1, -1};
  int n;
  cin >> n;
  vector<string> vin(n);
  for (int i = 0; i < n; i++)
    cin >> vin[i];
  vector<string> vout(vin);
  for (int i = 1; i < n-1; i++)
    for (int j = 1; j < n-1; j++)
      for (int d = 0; d < 5; d++)
        if (d == 4)
          vout[i][j] = 'X';
        else if (vin[i+dx[d]][j+dy[d]] >= vin[i][j])
          break;
  for (int i = 0; i < vout.size(); i++)
    cout << vout[i] << endl;
}
