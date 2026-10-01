#include <stdio.h>
void nhap(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("nhap gia tri vao mang:");
    scanf("%d", &a[i]);
  }
}
void xuat(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("[%d]", a[i]);
  }
  printf("\n");
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selection_sort(int a[], int n) {
  int min;
  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[min] > a[j])
        min = j;
    }
    swap(&a[min], &a[i]);
  }
}
int bs(int a[], int n, int x) {
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == x)
      return mid;
    else if (a[mid] > x)
        r = mid -1;
    else
        l = mid +1;
  }
  return -1;
}

int main() {
  int a[100], n;
  int x;
  printf("nhap so gia tri trong mang:");
  scanf("%d", &n);
  nhap(a, n);
  xuat(a, n);
  printf("\n --- sap xep ----\n");
  selection_sort(a,n);
  xuat(a, n);
  printf("nhap gia tri can tim trong mang:");
  scanf("%d", &x);
  int kq = bs(a, n, x);
  if (kq == -1)
    printf("%d khong co trong mang!\n", x);
  else
    printf("%d nam o vi tri %d! \n", x, kq);
  return 0;
}
