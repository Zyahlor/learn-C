#include <stdio.h>
void de_quy(int n) {
  if (n > 6)
    return;
  printf("[%d] ", n);
  de_quy(n + 1);
}
int main() {
  int n;
  printf("nhap n:");
  if (scanf("%d", &n) != 1){
      printf("input ko hop le!\n");
      return 1;
  }
  de_quy(n);
  printf("\n");
  return 0;
}
