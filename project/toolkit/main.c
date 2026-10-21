#include "toolkit.h"
#include <stdio.h>

int main(void) {
  int a[] = {4, 7, 1, 9, 7};
  int n = sizeof(a) / sizeof(a[0]);

  printf("goc:      ");
  printArr(a, n);

  int *m = findMax(a, n);
  printf("max = %d\n", *m);

  int *f = find(a, n, 1);
  if (f != NULL)
    printf("thay 1\n");
  if (find(a, n, 50) == NULL)
    printf("50: khong thay\n");

  reverse(a, n);
  printf("reverse:  ");
  printArr(a, n);
  bubbleSort(a, n);
  printf("xap xep:     ");
  printArr(a, n);

  fill(a, n, 0);
  printf("fill 0:   ");
  printArr(a, n);

  int b[] = {1, 2, 3, 4, 5};
  rotateLeft(b, 5, 2);
  printf("rotate:   ");
  printArr(b, 5); // 3 4 5 1 2

  int c[] = {5, 2, 9, 1, 7};
  bubbleSort(c, 5);
  printf("sort:     ");
  printArr(c, 5); // 1 2 5 7 9

  int d[] = {4, 7, 1, 9, 7, 4};
  int dn = 6;
  removeDup(d, &dn);
  printf("dedup:    ");
  printArr(d, dn);            // 4 7 1 9
  printf("n moi = %d\n", dn); // 4

  return 0;
}
