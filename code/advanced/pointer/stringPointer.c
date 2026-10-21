#include <stdio.h>

int main() {
  char name[] = "bao";
  char *Pstring = name;
  int n = sizeof(name) / sizeof(name[0]);
  int dem = 0;
  for (int i = 0; *(Pstring + i) != '\0'; i++) {
    dem++;
  }
  for (int i = 0; *(Pstring + i) != '\0'; i++) {
    printf("%c", *(Pstring + i));
  }
  printf("\nso tu co trong ten la:[%d]\n", dem);
  for (int i = n - 2; i >= 0; i--) {
    printf("%c", *(Pstring + i));
  }
  return 0;
}
