#include <stdio.h>
struct sv {
  char ten[20];
  int tuoi;
  float diem;
};
struct sv2 {
  int tuoi;
  float diem;
};
void insv(struct sv2 *p, int n);
int main() {
  struct sv sv1 = {"bao", 19, 8.5};
  struct sv *p = &sv1;
  printf("ten:%s\n", p->ten);
  printf("tuoi:%d\n", p->tuoi);
  printf("diem:%f\n", p->diem);
  p->tuoi = 20;
  p->diem = 9.0;
  printf("diem moi:%f | tuoi moi: %d\n", sv1.diem, sv1.tuoi);
  struct sv2 sv2[3] = {{18, 7.5}, {19, 8.0}, {20, 9.0}};
  struct sv2 *q = sv2;
  int i = 0;
  int n = sizeof(sv2) / sizeof(sv2[0]);
  while (i < n) {
    printf("%d | %f\n", (q + i)->tuoi, (q + i)->diem);
    i++;
  }
  (q + 1)->diem = 9.5;
  insv(sv2, n);
  return 0;
}
void insv(struct sv2 *p, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d | %f \n", (p + i)->tuoi, (p + i)->diem);
  }
}
