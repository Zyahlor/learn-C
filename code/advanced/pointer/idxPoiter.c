#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void nhap(int a[], int n);
void xuat(int a[], int n);
int main() {
  int a[5];
  int n = sizeof(a) / sizeof(a[0]);
  nhap(a, n);
  xuat(a, n);
  int *Pa = a;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(Pa + 1);
  }
  printf("tong cac phan tu trong mang la:[%d]\n", sum);
  return 0;
}
void nhap(int a[], int n) {
  srand(time(0));
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 10;
  }
}
void xuat(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("[%d] ", a[i]);
  }
  printf("\n");
}
