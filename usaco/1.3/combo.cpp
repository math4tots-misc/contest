/*
ID: math4to2
LANG: C++
TASK: combo
*/
#include <iostream>
#include <fstream>
using namespace std;
int N;
bool close(int a, int b) {
    return a > b ? close(b,a) : (b-a <= 2 || a+N-b <= 2);
}
bool match(int A, int B) {
    for (int i = 0; i < 3; i++) {
        if (!close(A%N, B%N))
            return false;
        A /= N;
        B /= N;
    }
    return true;
}
int main(int argc, char** argv) {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    fin >> N;
    int K[2];
    for (int i = 0; i < 2; i++) {
        K[i] = 0;
        for (int j = 0; j < 3; j++) {
            int x;
            fin >> x;
            K[i] *= N;
            K[i] += x-1;
        }
    }
    int total = 0;
    for (int i = 0; i < N * N * N; i++) {
        if (match(K[0],i) || match(K[1],i))
            total++;
    }
    fout << total << endl;
    return 0;
}