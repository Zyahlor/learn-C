#include "qlsv.h"
#include <stdio.h>
static void swap_struct(sv *x, sv *y) {
  sv tmp = *x;
  *x = *y;
  *y = tmp;
}
int tim(sv *x, int n, int masv) {
  for (int i = 0; i < n; i++) {
    if (masv == (x + i)->masv)
      return i;
  }
  return -1;
}
void hoandoi_diem(float *a, float *b) {
  float tmp = *a;
  *a = *b;
  *b = tmp;
}

void hoandoi(sv *x, int n, int masv1, int masv2) {

  int idx1 = tim(x, n, masv1);
  int idx2 = tim(x, n, masv2);

  if (idx1 != -1 && idx2 != -1) {
    hoandoi_diem(&(x + idx1)->diem, &(x + idx2)->diem);
  } else {
    printf("khong ton tai sinh vien\n");
  }
}
void giamdan(sv *x, int n) {
  sv *end = x + n;
  for (sv *p1 = x; p1 < end - 1; p1++) {
    for (sv *p2 = p1 + 1; p2 < end; p2++) {
      if (p1->diem < p2->diem) {
        swap_struct(p1, p2);
      }
    }
  }
}
static void max(sv *x, int n, int *max){
    *max = x->diem;
    sv *end = x+n;
    for(sv *p = x+1;p < end;p++){
       if(p->diem > *max){
            *max = p->diem;
       } 
    }
}
static void min(sv *x, int n, int *min){
    *min = x->diem;
    sv *end = x+n;
    for(sv *p = x+1;p < end;p++){
       if(p->diem < *min){
            *min = p->diem;
       } 
    }
}
void maxmin(sv *x, int n, int *out_max, int *out_min){
    max(x, n, out_max);
    min(x, n, out_min);
}
