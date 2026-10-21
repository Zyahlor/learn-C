#include "qlsv.h"
#include <stdio.h>
void sua(sv *x, int n, int masv, int luachon) {
  int idx = tim(x, n, masv);
  if (idx == -1) {
    printf("khong ton tai sinh vien\n");
    return;
  }
  sv *target = x + idx;
  switch (luachon) {
  case 1: {
    printf("=== sua massv ===\n");
    printf("massv:[%d]\n", target->masv);
    printf("nhap massv moi:");
    scanf("%d", &target->masv);
    printf("massv moi:[%d]\n", target->masv);
    break;
  }
  case 2: {
    printf("=== sua tuoi ===\n");
    printf("tuoi:[%d]\n", target->tuoi);
    printf("nhap tuoi moi:");
    scanf("%d", &target->tuoi);
    printf("tuoi moi:[%d]\n", target->tuoi);
    break;
  }
  case 3: {
    printf("=== sua diem ===\n");
    printf("diem:[%.2f]\n", target->diem);
    printf("nhap diem moi:");
    scanf("%f", &target->diem);
    printf("diem moi:[%.2f]\n", target->diem);
    break;
  }
  default:
    printf("Lua chon khong hop le!\n");
    break;
  }
}
sv *out_max(sv *x, int n) {
  if (n <= 0)
    return NULL;
  sv *most = x;
  for (int i = 0; i < n; i++) {
    if ((x + i)->diem > most->diem)
      most = x + i;
  }
  return most;
}
int kha(sv *x, int n) {
  int dem = 0;
  for (sv *p = x; p < x + n; p++) {
    if (p->diem >= 8)
      dem++;
  }
  return dem;
}
sv *out_massv(sv *x, int n, int masv) {
    if(n<=0) return NULL;
  sv *p = x;
  for (sv *q = x + 1; q < x + n; q++) {
      if(masv == q->masv ){
          p = q;
          break;
      }
  }
  if(p == x && p->masv != masv){
    printf("khong ton tai sinh vien");
    return NULL;
  }
  return p;
}
