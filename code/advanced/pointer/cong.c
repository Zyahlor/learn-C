#include <stdio.h>
void swap(int *a, int *b);
int main() {
  int a = 10, b = 20;
  int *Pa = &a;
  int *Pb = &b;
  int sum = *Pa + *Pb;
  printf("tong gia tri con tro cua %d va %d la:[%d]\n", a, b, sum);
  swap(Pa, Pb);
  printf("gia tri cua a va b thanh: a[%d] | b[%d]\n", *Pa, *Pb);
  return 0;
}
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
