#include "qlsv.h"
#include <stdio.h>

void nhap(sv *x, int n) {
  for (int i = 0; i < n; i++) {
    printf("nhap thong tin sinh vien [%d]:\n", i + 1);
    printf("nhap masv:");
    scanf("%d", &(x + i)->masv);
    printf("nhap tuoi:");
    scanf("%d", &(x + i)->tuoi);
    printf("nhap diem:");
    scanf("%f", &(x + i)->diem);
  }
}
void xuat(sv *x, int n) {
  for (int i = 0; i < n; i++) {
    printf("thong tin sinh vien [%d]:\n", i + 1);
    printf("mass:[%d] | tuoi:[%d] | diem:[%.2f]\n", (x + i)->masv,
           (x + i)->tuoi, (x + i)->diem);
  }
}
float tb(sv *x, int n) {
  float tong = x->diem;
  for (int i = 1; i < n; i++) {
    tong += (x + i)->diem;
  }
  return tong / n;
}
int max_diem(sv *x, int n) {
  float max = x->diem;
  int found = 0;
  for (int i = 1; i < n; i++) {
    if (max < (x + i)->diem) {
      max = (x + i)->diem;
      found = i;
    }
  }
  return found;
}
void tang_diem(sv *x, int n){
    for(int i =0;i<n;i++){
        (x+i)->diem +=2;
    }
}
