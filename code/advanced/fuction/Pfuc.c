#include <stdio.h>
void hoandoi(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void nhandoi(int *p) { *p *= 2; }
void capnhat(int *a, int *b) {
  int moi1 = *a, moi2 = *b;
  *a = moi1 + moi2;
  *b = moi1 - moi2;
}
void timmax(int *a, int *b, int *c) {
  int max = *a;
  if (max < *b)
    max = *b;
  if (max < *c)
    max = *c;
  *a = max;
}
void sapxep(int *a, int *b) {
  if (*a > *b) {
    hoandoi(a, b);
  }
}
void xuly(int *p, int *q) {
  *p += 5;
  *q = *p;
  *q *= 2;
}

int main() {
  // int a = 12;
  // int b = 5;
  // int c = 99;
  //
  // capnhat(&a, &b);
  // printf("%d %d \n", a, b);
  // timmax(&a, &b, &c);
  // printf("max:[%d]\n",a);
  int a = 3, b = 10;

  xuly(&a, &b);

  printf("%d %d", a, b);
  return 0;
}
