#include "thuvien.h"
#include <stdio.h>
void read_log(void) {
  FILE *f = fopen("auth.log", "r");
  if (f == NULL) {
    printf("[!] khong the mo file!\n");
    return;
  }
  char buffer[100];
  while (fgets(buffer, sizeof(buffer), f) != NULL) {
    printf("[+] %s", buffer);
  }
  fclose(f);
}
