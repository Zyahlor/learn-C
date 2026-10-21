#include <stdio.h>
void swap(int *a, int *b) {
  int tmp = *a;
  *b = *a;
  *a = tmp;
}
void reverse(int *arr, int n) {
  if (n <= 1 || arr == NULL) {
    printf("mang rong\n");
    return;
  }
  int *p = arr;
  int *q = arr + n - 1;
  while (p < q) {
    swap(p, q);
    p++;
    q--;
  }
}
int main() {
  printf("hello\nworld!\n");
  int arr[] = {1,4,1,5,7,3,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("chua doi:\n");
  for(int x = 0;x<n;x++){
      printf("[%d] ", arr[x]);
  }
  printf("\n");
  reverse(arr, n);
   for(int x = 0;x<n;x++){
      printf("[%d] ", arr[x]);
  } return 0;
}
