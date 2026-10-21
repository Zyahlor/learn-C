#include <stdio.h>
void copy(char *dst, const char *src) {
  int i = 0;
  while (*(src + i) != '\0') {
      *(dst + i) = *(src +i);
    i++;
  }
  // *(dst + i) = '\0';
}
int count_string(const char *s) {
  int count = 0;
  while (*(s + count) != '\0') {
    count++;
  }
  return count;
}
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void reverese(int *arr, int n) {
  if (arr == NULL || n <= 1) {
    return;
  }
  int *p = arr;
  int *q = arr + n - 1;
  while (p < q) {
    swap(q, p);
    // di chuyen 2 con tro
    p++;
    q--;
  }
}
int max_arr(int *arr, int n) {
  int max_Val = *arr;
  if (arr == NULL || n <= 0)

    for (int i = 1; i < n; i++) {
      if (max_Val < *(arr + i)) {
        max_Val = *(arr + i);
      }
    }
  return max_Val;
}

int main() {

  printf("==== basic ==== \n");
  printf("bai 1:\n");
  int a = 5;
  int *p = &a;
  printf("%d\n", a);
  printf("%p\n", p);
  printf("%d\n", *p);
  printf("doi gia tri:\n");
  *p = 50;
  printf("%d\n", a);
  printf("%p\n", p);
  printf("%d\n", *p);

  printf("bai 2:\n");
  int so_1 = 5, so_2 = 10;
  printf("chua chuyen:\n");
  printf("so_1:[%d] | so_2:[%d]\n", so_1, so_2);
  swap(&so_1, &so_2);
  printf("so_1:[%d] | so_2:[%d]\n", so_1, so_2);

  printf("bai 3:\n");
  int arr[] = {5, 6, 23, 4, 34, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  if (n <= 0) {
    printf("mang rong!\n");
  } else {
    int max_Val = max_arr(arr, n);
    printf("gia tri max trong mang la:%d\n", max_Val);
  }
  printf("bai 4:\n");
  for (int x = 0; x < n; x++) {
    printf("[%d] ", arr[x]);
  }
  printf("\n");
  reverese(arr, n);
  for (int x = 0; x < n; x++) {
    printf("[%d] ", arr[x]);
  }
  printf("\n");
  printf("bai 5:\n");
  char s[] = "";
  int kq = count_string(s);
  printf("%d\n", kq);
  printf("bai 6: \n");
  char chuoi[20];
  copy(chuoi, "hellassadfafo");
  printf("%s \n",chuoi);
  return 0;
}
