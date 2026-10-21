#include "toolkit.h"
#include <stdio.h>
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void printArr(const int *a, int n) {
  for (const int *p = a; p < a + n; p++)
    printf("%d ", *p);
  printf("\n");
}

void fill(int *a, int n, int v) {
  for (int *p = a; p < a + n; p++) {
    *p = 0;
  }
}

int *find(int *a, int n, int x) {
  for (int *p = a; p < a + n; p++) {
    if (*p == x)
      return p;
  }
  return NULL;
}

void reverse(int *a, int n) {
  int *l = a;         // con trỏ đầu
  int *r = a + n - 1; // con trỏ cuối
  while (l < r) {
    int tmp = *l;
    *l = *r;
    *r = tmp;
    l++;
    r--;
  }
}

int *findMax(int *a, int n) {
  int *maxp = a;
  for (int *p = a + 1; p < a + n; p++) {
    if (*p > *maxp)
      maxp = p;
  }
  return maxp;
}
void rotateLeft(int *a, int n, int k) {
  for (int i = 0; i < k; i++) {
    int t = *a; // lưu ô đầu
    for (int *p = a; p < a + n - 1; p++)
      *p = *(p + 1);  // dịch mọi ô sang trái
    *(a + n - 1) = t; // ô đầu cũ xuống cuối
  }
}
void bubbleSort(int *a, int n) {
  int *p = a;
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (*(p + j) < *(p + j - 1)) {
        swap((p + j), (p + j - 1));
      }
    }
  }
}
void removeDup(int *a, int *n) {
  for (int *p = a; p < a + *n; p++) {
    int *q = p + 1;

    while (q < a + *n) {
      if (*q == *p) {
        // Dồn các ô sau q lên 1 ô
        for (int *s = q; s < a + *n - 1; s++)
          *s = *(s + 1);

        (*n)--; // Giảm số phần tử

      } else {
        q++;
      }
    }
  }
}
