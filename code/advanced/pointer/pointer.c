#include <stdio.h>

int main() {
  int a = 10;
  int *p = &a;
  printf("%d\n", a);
  printf("%p\n", p);
  printf("%d\n", *p);
  printf(" == doi ==\n");
  *p = 20;
  printf("%d\n", a);
  printf("%p\n", p);
  printf("%d\n", *p);
  int arr[3] = {1,2,3};
  int *m = arr; //  = &arr[0]
  printf("%d\n",*m);
  printf("%d\n",*(m+1));
  printf("%d\n",m[2]);
  return 0;
}
