#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int massv;
  int tuoi;
  float diem;
} sv;
sv *capphat(int n) {
  sv *tmp = malloc(n * (sizeof(sv)));
  if (tmp == NULL) {
    return NULL;
  }
  return tmp;
}
void nhap(sv *a, int n) {
  for (sv *i = a; i < a + n; i++) {
    printf("nhap massv:");
    scanf("%d", &i->massv);
    printf("nhap tuoi:");
    scanf("%d", &i->tuoi);
    printf("nhap diem:");
    scanf("%f", &i->diem);
  }
}
void xuat(sv *a, int n) {
  for (sv *i = a; i < a + n; i++) {
    printf("massv:[%d]\n", i->massv);
    printf("tuoi:[%d]\n", i->tuoi);
    printf("diem:[%.2f]\n", i->diem);
  }
}
sv *morong(sv *a, int *n) {
  int them;

  printf("nhap so luong can them:");

  if (scanf("%d", &them) != 1 || them <= 0) {
    return NULL;
  }

  sv *tmp = realloc(a, (*n + them) * sizeof(sv));

  if (tmp == NULL) {
    return NULL;
  }

  nhap(tmp + *n, them);

  *n += them;

  return tmp;
}
void giai_phong(sv **a) {
  free(*a);
  *a = NULL;
}
int main() {
  int n = 1;
  sv *sv1 = capphat(n);
  if (sv1 == NULL) {
    printf("khong the cap phat!");
    return 1;
  }
  printf("=== nhap ===\n");
  nhap(sv1, n);
  printf("=== xuat ===\n");
  xuat(sv1, n);
  printf("=== them ===\n");
  sv *tmp = morong(sv1, &n);

  if (tmp == NULL) {
    printf("khong the mo rong!");
    free(sv1);
    return 1;
  }

  sv1 = tmp;
  printf("=== xuat ===\n");
  xuat(sv1, n);
  giai_phong(&sv1);
  return 0;
}
