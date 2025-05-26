#include <stdio.h>

int calc(int a, int b, int c, int d, int e, int f) {
  return (a + b + c) * (d + e + f);
}

int main() {
  int result = calc(2, 3, 4, 4, 3, 2);
  printf("Result: %d\n", result);
}

