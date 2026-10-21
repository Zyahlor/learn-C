#include <stdio.h>
void f(int n) {
  printf("ngan xep f(%d) duoc day vao!\n", n);
  if (n > 1) {
    f(n - 1);
    f(n - 1);
  }
  printf("ngan xep f(%d) bi xoa!\n", n);
}
int main() { 
f(3);


    return 0; }
