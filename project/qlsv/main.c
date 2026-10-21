#include "qlsv.h"
#include <stdio.h>
struct sv;

int main() {
  sv ds[] = {
      {101, 20, 6.5f},
      {102, 19, 9.0f},
      {103, 21, 4.5f},
      {104, 20, 8.0f},
      {105, 22, 7.5f}
  };
  int n = sizeof(ds) / sizeof(ds[0]);

  printf("========== 1. DANH SACH BAN DAU ==========\n");
  xuat(ds, n);

  printf("\n========== 2. THONG KE (TB & MAX) ==========\n");
  float kq = tb(ds, n);
  printf("Diem trung binh ca lop: %.2f\n", kq);
  int max_idx = max_diem(ds, n);
  printf("Sinh vien diem cao nhat: MaSV [%d] | Tuoi [%d] | Diem [%.2f]\n",
         ds[max_idx].masv, ds[max_idx].tuoi, ds[max_idx].diem);

  printf("\n========== 3. TEST TANG DIEM (+2) ==========\n");
  tang_diem(ds, n);
  xuat(ds, n);

  printf("\n========== 4. TEST HOAN DOI DIEM (MaSV 101 va 103) ==========\n");
  printf("Diem truoc khi doi: SV 101 = %.2f, SV 103 = %.2f\n", ds[0].diem, ds[2].diem);
  hoandoi(ds, n, 101, 103);
  printf("Diem sau khi doi:   SV 101 = %.2f, SV 103 = %.2f\n", ds[0].diem, ds[2].diem);

  printf("\n========== 5. TEST SAP XEP GIAM DAN THEO DIEM ==========\n");
  giamdan(ds, n);
  xuat(ds, n);
  printf("\n========== 6. TEST MAX MIN ==========\n");
  int max_val, min_val;
  maxmin(ds, n, &max_val, &min_val);
  printf("Diem Max (nguyen): %d | Diem Min (nguyen): %d\n", max_val, min_val);

  printf("\n========== 7. TEST CON TRO TOP 1 (out_max) ==========\n");
  sv *top1 = out_max(ds, n);
  if (top1) {
    printf("Sinh vien diem cao nhat: MaSV [%d] | Tuoi [%d] | Diem [%.2f]\n",
           top1->masv, top1->tuoi, top1->diem);
  }

  printf("\n========== 8. TEST DEM SINH VIEN KHA/GIOI (diem >= 8) ==========\n");
  int so_sv_kha = kha(ds, n);
  printf("So sinh vien co diem >= 8: %d sinh vien\n", so_sv_kha);

  printf("\n========== 9. TEST TIM KIEM THEO MASV (out_massv) ==========\n");
  printf("--> Tim kiem MaSV 104:\n");
  sv *tim_thay = out_massv(ds, n, 104);
  if (tim_thay) {
    printf("Tim thay: MaSV [%d] | Tuoi [%d] | Diem [%.2f]\n",
           tim_thay->masv, tim_thay->tuoi, tim_thay->diem);
  }
  printf("--> Tim kiem MaSV 999 (khong ton tai):\n");
  sv *ko_thay = out_massv(ds, n, 999);
  if (!ko_thay) {
    printf("Ket qua: Dung la khong tim thay (NULL)\n");
  }

  return 0;
}
