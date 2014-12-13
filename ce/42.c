// This only scores a 90... So I'm still missing something...
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int solve(char * number) {
  int digits[14], ops[12], i, length, ugly_count = 0;
  
  memset(ops, 0, sizeof(ops));
  length = strlen(number);
  
  for (i = 0; i < length; i++)
    digits[i] = number[i] - '0';
  
  // loop over all possible expressions
  while (ops[0] == 0) {
    int total = 0, chunk = 0, sign = 1;
    
    // calculate the total for this expression.
    for (i = 0; i < length; i++) {
      if (ops[i]) {
        if (sign == 1) total += chunk;
        else           total -= chunk;
        sign = ops[i];
        chunk = 0;
      }
      chunk *= 10;
      chunk += digits[i];
    }
    if (sign == 1) total += chunk;
    else           total -= chunk;
    
    // increment the ugly count if total is ugly.
    if (total % 2 == 0 || total % 3 == 0 || total % 5 == 0 || total % 7 == 0)
      ugly_count++;
    
    // next ops combination
    for (i = length-1; ops[i] == 2; i--)
      ops[i] = 0;
    ops[i]++;
  }
  return ugly_count;
}

int main(int argc, char** argv) {
  FILE * fin = fopen(argv[1], "r");
  char line[80];
  while (fgets(line, 80, fin)) {
    int length = 0;
    while (isdigit(line[length]))
      length++;
    line[length] = '\0';
    printf("%d\n", solve(line));
  }
}
