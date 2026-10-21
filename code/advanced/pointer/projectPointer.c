#include <stdio.h>
int my_strcmp(char a[], char b[]);
int my_strlen(char a[]);
void my_strcpy(char a[], char b[]);
void my_strrev(char a[]);
char *my_strchr(char a[], char b);
int main() {
  char name[10];
  printf("nhap ten cua ban:");
  fgets(name, sizeof(name), stdin);
  printf("toi ten la:%s\n", name);
  printf("ten ban co %d ky tu!\n", my_strlen(name));
  const int n = sizeof(name) / sizeof(name[0]);
  char name_b[n];
  my_strcpy(name, name_b);
  printf("chuoi moi la:%s\n", name_b);
  printf("ten ban co %d ky tu!\n", my_strlen(name_b));
  char new_name[] = "ban";
  int kq = my_strcmp(name, new_name);
  if (kq != 0)
    printf("2 chuoi ko giong nhau!\n");
  else
    printf("2 chuoi giong nhau!\n");
  printf("=== dao chuoi ===\n");
  my_strrev(name);
  printf("=== tim chuoi ===\n");
  char *irl = my_strchr(name, 'n');
  if(*irl == 'n') printf("dia chi cua chuoi: %s\n",irl);
  else printf("khong co trong chuoi!\n");
  return 0;
}

int my_strlen(char a[]) {
  char *p = a;
  int dem = 0;
  while (*p != '\0') {
    dem++;
    p += 1;
  }
  return dem - 1;
}

void my_strcpy(char a[], char b[]) {
  char *p = a;
  int i;
  for (i = 0; *(p + i) != '\0'; i++) {
    b[i] = *(p + i);
  }
  b[i] = '\0';
}
int my_strcmp(char a[], char b[]) {
  char *p = a;
  char *q = b;
  while (*p != '\0' && *q != '\0') {
    if (*p != *q)
      return 1;
    p += 1;
    q += 1;
  }
  if (*p != *q)
    return 1;
  return 0;
}
void my_strrev(char a[]) {
  char *p = a;
  int i = 0, kq = my_strlen(a);
  while (i < kq / 2) {
    char tmp = *(p + i);
    *(p + i) = *(p + kq - i - 1);
    *(p + kq - i - 1) = tmp;
    i++;
  }
  printf("chuoi da dao:%s", a);
}
char *my_strchr(char a[], char b) {
  char *p = a;
  while (*p != '\0') {
    if (*p == b)
      return p;
    p++;
  }
  return NULL;
}
