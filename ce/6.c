#include <stdio.h>
#include <string.h>
static char A[51], B[51], C[51];

static void solve_one() {
  char a, b, *c = C, t, AL, BL, l[51][51], ch[51][51], na[51][51], nb[51][51];
  AL = strlen(A);
  BL = strlen(B);
  for (a = 0; a <= AL; a++) l[a][BL] = 0;
  for (b = 0; b <  BL; b++) l[AL][b] = 0;
  for (a = AL-1; a >= 0; a--) {
    for (b = BL-1; b >= 0; b--) {
      if (A[a] == B[b]) {
        l[a][b] = l[a+1][b+1] + 1;
        na[a][b] = a+1;
        nb[a][b] = b+1;
        ch[a][b] = A[a];
      } else if (l[a+1][b] > l[a][b+1]) {
        l[a][b] = l[a+1][b];
        na[a][b] = a+1;
        nb[a][b] = b;
        ch[a][b] = 0;
      } else {
        l[a][b] = l[a][b+1];
        na[a][b] = a;
        nb[a][b] = b+1;
        ch[a][b] = 0;
      }
    }
  }
  for (a = b = 0; a < AL && b < BL; t = a, a = na[a][b], b = nb[t][b]) {
    if (ch[a][b])
      *c++ = ch[a][b];
    *c = '\0';
  }
}

static void solve(char * fname) {
  char s[103], *p, *q;
  FILE * fin = fopen(fname, "r");
  while (fgets(s, 103, fin)) {
    p = s; while (*p != ';' ) p++;
    q = p; while (*q != '\n') q++;
    *p = *q = '\0';
    strcpy(A, s);
    strcpy(B, p+1);
    solve_one();
    printf("%s\n", C);
  }
}

int main(int argc, char** argv) {
  solve(argv[1]);
  return 0;
}
